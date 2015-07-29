// Copyright (c) 2014 Hasso-Plattner-Institut fuer Softwaresystemtechnik GmbH. All rights reserved.
#include "access/sql/SQLDataDefinitionTransformer.h"
#include "access/sql/SQLStatementTransformer.h"
#include "access/sql/transformation_helper.h"
#include "access/sql/PreparedStatementManager.h"

#include "io/StorageManager.h"

#include "access/storage/TableLoad.h"
#include "access/storage/TableUnload.h"
#include "access/storage/JsonTable.h"
#include "access/storage/SetTable.h"
#include "access/CreateIndex.h"
#include "access/CreateGroupkeyIndex.h"
#include "access/CreateDeltaIndex.h"
#include "access/DropIndex.h"


using namespace hsql;

namespace hyrise {
namespace access {
namespace sql {

SQLDataDefinitionTransformer::SQLDataDefinitionTransformer(SQLStatementTransformer& server) :
  _server(server),
  _builder(server.getTaskListBuilder()) {}

SQLDataDefinitionTransformer::~SQLDataDefinitionTransformer() {}

/**
 * Transforms a create statement into tasks
 */
TransformationResult SQLDataDefinitionTransformer::transformCreateStatement(CreateStatement* create) {
  TransformationResult meta = ALLOC_TRANSFORMATIONRESULT();

  if (io::StorageManager::getInstance()->exists(create->table_name) && (create->type == CreateStatement::kTableFromTbl || create->type == CreateStatement::kTable)) {
    if (create->if_not_exists) {
      // Table already exists so skip this statement
      _builder.addNoOp(meta);
      return meta;
    } else {
      // Table already exists -> throw error
      _server.throwError("Table already exists", create->table_name);
    }
  }

  if (create->type == CreateStatement::kTableFromTbl) {
    // Create TableLoad
    auto table_load = std::make_shared<TableLoad>();//addNewPlanOp<TableLoad>("TableLoad", meta);
    table_load->setTableName(std::string(create->table_name));
    table_load->setFileName(std::string(create->file_path));
    _builder.addPlanOp(table_load, "TableLoad", meta);

  } else if (create->type == CreateStatement::kTable) {
    // Create and SetTable
    std::vector<std::string> names;
    std::vector<std::string> types;
    std::vector<unsigned> groups;

    for (ColumnDefinition* def : *create->columns) {
      names.push_back(def->name);
      groups.push_back(1);
      switch (def->type) {
        case ColumnDefinition::INT: types.push_back("INTEGER"); break;
        case ColumnDefinition::TEXT: types.push_back("STRING"); break;
        case ColumnDefinition::DOUBLE: types.push_back("FLOAT"); break;
      }
    }

    auto json_table = std::make_shared<JsonTable>();
    json_table->setNames(names);
    json_table->setTypes(types);
    json_table->setGroups(groups);
    json_table->setUseStore(true);
    _builder.addPlanOp(json_table, "JsonTable", meta);

    // Give it a name and persist it within Hyrise storage manager
    auto set_table = std::make_shared<SetTable>(create->table_name);
    set_table->addDependency(json_table);
    _builder.addPlanOp(set_table, "SetTable");

    meta.addTask(json_table);
    meta.addTask(set_table);

  } else if(create->type == CreateStatement::kIndex) {

    meta = _server.addGetTable(create->table_name, true);

    // if(create->index_type == CreateStatement::kDefaultIndex) {

    //   auto create_index = std::make_shared<CreateIndex>();
    //   create_index->setIndexName(create->index_name);

    //   for (unsigned i = 0; i < create->index_columns->size(); ++i) {
    //     create_index->addField(Json::Value(create->index_columns->at(i)));
    //   }

    //   _builder.addPlanOp(create_index, "CreateIndex", meta);


    // } else if(create->index_type == CreateStatement::kGroupKeyIndex) {

      auto create_index = std::make_shared<CreateGroupkeyIndex>();
      create_index->setIndexName(std::string(create->index_name) + "_main");

      for (unsigned i = 0; i < create->index_columns->size(); ++i) {
        create_index->addField(Json::Value(create->index_columns->at(i)));
      }

      _builder.addPlanOp(create_index, "CreateGroupkeyIndex", meta);


      // auto create_delta_index = std::make_shared<CreateDeltaIndex>();
      // create_index->setIndexName(std::string(create->index_name) + "_delta");

      // for (unsigned i = 0; i < create->index_columns->size(); ++i) {
      //   create_delta_index->addField(Json::Value(create->index_columns->at(i)));
      // }

      // _builder.addPlanOp(create_delta_index, "CreateDeltaIndex", meta);


    // } else {
    //   _server.throwError("Unsupported index type!");
    // }



  } else {
    _server.throwError("Unsupported create type!");
  }

  // Add No op, so we don't send data back
  _builder.addCommit(meta);
  _builder.addNoOp(meta);

  return meta;
}



TransformationResult SQLDataDefinitionTransformer::transformDropStatement(DropStatement* drop) {
  TransformationResult meta = {};

  switch (drop->type) {
    case DropStatement::kTable: {
      if (!io::StorageManager::getInstance()->exists(drop->name)) {
        _server.throwError("Can't drop table. It doesn't exist.", drop->name);
      }

      auto drop_op = std::make_shared<TableUnload>();
      drop_op->setTableName(drop->name);
      _builder.addPlanOp(drop_op, "TableUnload", meta);
      _builder.addCommit(meta);
      break;
    }

    case DropStatement::kPreparedStatement: {
      if (PreparedStatementManager::getInstance().hasStatement(drop->name)) {
        PreparedStatementManager::getInstance().deleteStatement(drop->name);
      } else {
        _server.throwError("Can't drop statement. It doesn't exist.", drop->name);
      }
      _builder.addNoOp(meta);
      break;
    }

    case DropStatement::kIndex: {

      if (!io::StorageManager::getInstance()->exists(drop->name)) {
        _server.throwError("Can't drop index. It doesn't exist.", drop->name);
      }

      auto drop_op = std::make_shared<DropIndex>();
      drop_op->setIndexName(drop->name);
      _builder.addPlanOp(drop_op, "DropIndex", meta);
      _builder.addCommit(meta);

      break;
    }

    default:
      _server.throwError("Drop type not supported");
  }

  return meta;
}



} // namespace sql
} // namespace access
} // namespace hyrise