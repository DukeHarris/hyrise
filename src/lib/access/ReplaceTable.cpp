#include "access/ReplaceTable.h"

#include "access/QueryParser.h"
#include "io/StorageManager.h"

static auto registered = QueryParser::registerPlanOperation<ReplaceTable>("ReplaceTable");

ReplaceTable::ReplaceTable(const std::string& name) : _name(name) {}

ReplaceTable::~ReplaceTable() {}

std::shared_ptr<_PlanOperation> ReplaceTable::parse(Json::Value& data) {
  return std::make_shared<ReplaceTable>(data["name"].asString());
}

const std::string ReplaceTable::vname() {
  return "ReplaceTable";
}

void ReplaceTable::executePlanOperation() {
  auto table = input.getTable();

  // TODO: For now do the bad way, SM should have const tables
  StorageManager::getInstance()->replaceTable(_name, std::const_pointer_cast<AbstractTable>(table));
  output.add(table);
}