// Copyright (c) 2012 Hasso-Plattner-Institut fuer Softwaresystemtechnik GmbH. All rights reserved.
#ifndef SRC_LIB_ACCESS_DROPINDEX_H_
#define SRC_LIB_ACCESS_DROPINDEX_H_

#include "access/system/PlanOperation.h"

namespace hyrise {
namespace access {

class DropIndex : public PlanOperation {
 public:
  virtual ~DropIndex();
  DropIndex();

  void executePlanOperation();
  /// set index name in field "_index_name"
  static std::shared_ptr<PlanOperation> parse(const Json::Value& data);
  void setIndexName(const std::string& t);

 private:
  std::string _index_name;
};
}
}

#endif  // SRC_LIB_ACCESS_DROPINDEX_H_
