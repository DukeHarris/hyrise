// Copyright (c) 2012 Hasso-Plattner-Institut fuer Softwaresystemtechnik GmbH. All rights reserved.
#include "access/DropIndex.h"

#include <string>
#include <vector>
#include <map>

#include "access/system/BasicParser.h"
#include "access/system/QueryParser.h"

#include "io/StorageManager.h"

#include "storage/AbstractTable.h"
#include "storage/meta_storage.h"
#include "storage/storage_types.h"
#include "storage/PointerCalculator.h"
#include "storage/AbstractIndex.h"
#include "storage/InvertedIndex.h"
#include "storage/Store.h"

namespace hyrise {
namespace access {

namespace {
auto _ = QueryParser::registerPlanOperation<DropIndex>("DropIndex");
}

DropIndex::~DropIndex() {}
DropIndex::DropIndex() {}

void DropIndex::executePlanOperation() {

  auto sm = io::StorageManager::getInstance();
  sm->removeIndex(_index_name);

}

std::shared_ptr<PlanOperation> DropIndex::parse(const Json::Value& data) {
  auto i = BasicParser<DropIndex>::parse(data);
  i->setIndexName(data["index_name"].asString());
  return i;
}

void DropIndex::setIndexName(const std::string& t) { _index_name = t; }
}
}
