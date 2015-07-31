// Copyright (c) 2012 Hasso-Plattner-Institut fuer Softwaresystemtechnik GmbH. All rights reserved.
#include "io/ResourceManager.h"

#include "helper/stringhelpers.h"
#include "helper/Environment.h"
#include "storage/AbstractResource.h"
#include "storage/Store.h"
#include <iostream>

namespace hyrise {
namespace io {

ResourceManager& ResourceManager::getInstance() {
  static ResourceManager rm;
  return rm;
}

template <typename T>
std::unique_lock<T> lock_guard(T& mtx) {
  return std::move(std::unique_lock<T>(mtx));
}

size_t ResourceManager::size() const {
  auto lock = lock_guard(_resource_mutex);
  return _resources.size();
}

bool ResourceManager::exists(const std::string& name, bool unsafe) const {
  if (!unsafe)
    auto lock = lock_guard(_resource_mutex);
  return _resources.count(name) == 1;
}

void ResourceManager::assureExists(const std::string& name, bool unsafe) const {
  if (!unsafe)
    auto lock = lock_guard(_resource_mutex);
  if (!exists(name, unsafe)) {
    throw ResourceNotExistsException("ResourceManager: Resource \'" + name + "\' does not exist");
  }
}

void ResourceManager::clear() const {
  auto lock = lock_guard(_resource_mutex);
  _resources.clear();
}

void ResourceManager::remove(const std::string& name) const {
  auto lock = lock_guard(_resource_mutex);
  assureExists(name);
  _resources.erase(name);
}

void ResourceManager::replace(const std::string& name,
                              const std::shared_ptr<storage::AbstractResource>& resource) const {
  auto lock = lock_guard(_resource_mutex);
  assureExists(name);
  _resources.at(name) = resource;
}

void ResourceManager::add(const std::string& name, const std::shared_ptr<storage::AbstractResource>& resource) const {
  auto lock = lock_guard(_resource_mutex);
  if (exists(name)) {
    throw ResourceAlreadyExistsException("ResourceManager: Resource '" + name + "' already exists");
  }

  auto store = std::dynamic_pointer_cast<storage::Store>(resource);
  if (store) {
    store->enableLogging();
  }
  _resources.insert(make_pair(name, resource));
}

std::shared_ptr<storage::AbstractResource> ResourceManager::getResource(const std::string& name, bool unsafe) const {
  if (!unsafe)
    auto lock = lock_guard(_resource_mutex);
  assureExists(name, unsafe);
  return _resources.at(name);
}

ResourceManager::resource_map ResourceManager::all() const {
  auto lock = lock_guard(_resource_mutex);
  return _resources;
}


void ResourceManager::recordColumnScan(std::thread::id thread_id, std::string table, std::vector<int> fields){

  columnScanStatisticsEntry scanEntry;
  scanEntry.table = table;
  scanEntry.fields = fields;

  std::cout << table << std::endl;
  std::cout << thread_id << std::endl;
  std::cout << "empty before:" << columnScanStatistics.empty() << std::endl;
  std::cout << "size before:" << columnScanStatistics.size() << std::endl;

  if(columnScanStatistics.count(thread_id) == 1){
    columnScanStatistics[thread_id].push_back(scanEntry);
  } else {
    columnScanStatistics[thread_id] = std::vector<columnScanStatisticsEntry>();
    columnScanStatistics[thread_id].push_back(scanEntry);
  }

  std::cout << "size after:" << columnScanStatistics.size() << std::endl;
  std::cout << columnScanStatistics[thread_id].size() << std::endl;
  std::cout << columnScanStatistics[thread_id].back().table << std::endl;

}


}
}  // namespace hyrise::io
