// Copyright (c) 2012 Hasso-Plattner-Institut fuer Softwaresystemtechnik GmbH. All rights reserved.
#include "access/MergeTable.h"

#include "access/system/QueryParser.h"

#include "helper/checked_cast.h"
#include "storage/Store.h"
#include "storage/ColumnStoreMerger.h"

namespace hyrise {
namespace access {

namespace {
auto _ = QueryParser::registerPlanOperation<MergeTable>("MergeTable");
}

MergeTable::~MergeTable() {}

void MergeTable::executePlanOperation() {
  std::vector<storage::c_atable_ptr_t> tables;
  // Add all tables to the game
  for (auto& table : input.getTables()) {
    if (auto store = std::dynamic_pointer_cast<const storage::Store>(table)) {
      tables.push_back(store->getMainTable());
      tables.push_back(store->getDeltaTable());
    } else {
      tables.push_back(table);
    }
  }

  // Call the Merge
  storage::TableMerger merger(new storage::DefaultMergeStrategy(), new storage::SequentialHeapMerger());
  auto new_table = input.getTable(0)->copy_structure();

  // Switch the tables
  auto merged_tables = merger.mergeToTable(new_table, tables);
  const auto& result = std::make_shared<storage::Store>(new_table);

  output.add(result);
}

std::shared_ptr<PlanOperation> MergeTable::parse(const Json::Value& data) { return std::make_shared<MergeTable>(); }

const std::string MergeTable::vname() { return "MergeTable"; }

namespace {
auto _2 = QueryParser::registerPlanOperation<MergeStore>("MergeStore");
}

MergeStore::~MergeStore() {}

void MergeStore::executePlanOperation() {
  auto t = checked_pointer_cast<const storage::Store>(getInputTable());
  auto store = std::const_pointer_cast<storage::Store>(t);
  store->merge();
  addResult(store);
}

std::shared_ptr<PlanOperation> MergeStore::parse(const Json::Value& data) { return std::make_shared<MergeStore>(); }

namespace {
auto _3 = QueryParser::registerPlanOperation<MergeColumnStore>("MergeColumnStore");
}

MergeColumnStore::MergeColumnStore(bool forceFullIndexRebuild, std::string sortIndexName)
    : _forceFullIndexRebuild(forceFullIndexRebuild), _sortIndexName(sortIndexName) {};

MergeColumnStore::~MergeColumnStore() {}

void MergeColumnStore::executePlanOperation() {
  auto t = checked_pointer_cast<const storage::Store>(getInputTable());
  auto store = std::const_pointer_cast<storage::Store>(t);

  //Drop all indices, because multi-column index merge is not supported
  store->clearIndices();
  std::cout << "Table merge!" << std::endl;

  storage::ColumnStoreMerger merger = storage::ColumnStoreMerger(store, _forceFullIndexRebuild, _sortIndexName);

  if (!store->isColumnStore())
    throw std::runtime_error("Column Store Merge applied to a table with row or hybrid layout");

  merger.merge();
  addResult(store);
}

std::shared_ptr<PlanOperation> MergeColumnStore::parse(const Json::Value& data) {
  bool forceFullIndexRebuild = false;
  std::string sortIndexName = "";

  if (data.isMember("force_full_index_rebuild"))
    forceFullIndexRebuild = data["force_full_index_rebuild"].asBool();

  if (data.isMember("sortIndexName"))
    sortIndexName = data["sortIndexName"].asBool();

  return std::make_shared<MergeColumnStore>(forceFullIndexRebuild, sortIndexName);
}

void MergeColumnStore::setForceFullIndexRebuild(bool force) { _forceFullIndexRebuild = force; }

void MergeColumnStore::setSortIndexName(std::string sortIndexName) { _sortIndexName = sortIndexName; }
}
}
