// Copyright (c) 2012 Hasso-Plattner-Institut fuer Softwaresystemtechnik GmbH. All rights reserved.
#include "access/GetScanStatistics.h"

#include "access/system/QueryParser.h"
#include "access/system/BasicParser.h"

#include "io/StorageManager.h"
#include "io/ResourceManager.h"

#include "storage/storage_types.h"
#include "storage/TableBuilder.h"
#include "storage/ColumnMetadata.h"
#include "storage/Table.h"

#include <iostream>
#include <algorithm>

namespace hyrise {
namespace access {

namespace {
auto _ = QueryParser::registerTrivialPlanOperation<GetScanStatistics>("GetScanStatistics");
}


void GetScanStatistics::executePlanOperation() {

  storage::TableBuilder::param_list list;
  list.append().set_type("STRING").set_name("table");
  list.append().set_type("STRING").set_name("columns");
  list.append().set_type("INTEGER").set_name("scan_counter");
  auto result = storage::TableBuilder::build(list);

  std::map<std::string, std::map<std::string, int>> combinedStats;

  io::StorageManager* sm = io::StorageManager::getInstance();
  std::map<std::thread::id, std::vector<io::ResourceManager::columnScanStatisticsEntry>> scanStats = sm->getColumnScanStatistics();

  // for(unsigned int thread=0; thread<scanStats.size(); thread++ ){
  for (const auto& thread : scanStats) {
    for(unsigned int entry=0; entry < thread.second.size(); entry++){

      if(combinedStats.count(thread.second.at(entry).table) == 0){
        combinedStats[thread.second.at(entry).table] = std::map<std::string, int>();
      }

      // create string from fields vector
      std::stringstream ss;
      std::vector<int> v = thread.second.at(entry).fields;
      std::sort(v.begin(), v.end());
      for(size_t i = 0; i < v.size(); i++)
      {
        if(i != 0)
          ss << ",";
        ss << v[i];
      }
      std::string fieldString = ss.str();
      std::cout << fieldString << std::endl;

      // check if key exists
      if(combinedStats[thread.second.at(entry).table].count(fieldString) == 0){
        combinedStats[thread.second.at(entry).table][fieldString] = 0;
      }

      // increase counter
      combinedStats[thread.second.at(entry).table][fieldString]++;

      // std::cout << thread.first << std::endl;
      // std::cout << scanStats[thread.first].at(entry).table << std::endl;
      // std::cout <<scanStats[thread.first].at(entry).fields[0] << std::endl;


    }
  }


  size_t row_count = 0;
  for (const auto& table : combinedStats) {
    result->resize(result->size() + combinedStats[table.first].size());

    for (const auto& fields : table.second){
      result->setValue<hyrise_string_t>(result->numberOfColumn("table"), row_count, table.first);
      result->setValue<hyrise_string_t>(result->numberOfColumn("columns"), row_count, fields.first);
      result->setValue<hyrise_int_t>(result->numberOfColumn("scan_counter"), row_count, fields.second);
      row_count++;
    }

  }






  // result->resize(result->size() + 1);
  // result->setValue<hyrise_string_t>(result->numberOfColumn("table"), 0, "tableName");
  // result->setValue<hyrise_string_t>(result->numberOfColumn("columns"), 0, "columnString");
  // result->setValue<hyrise_int_t>(result->numberOfColumn("scan_counter"), 0, 123);
  addResult(result);

}
}
}