#include "hns.h"
#include <algorithm>
#include <functional>
using std::hash;
using std::string;
using std::find_if;

HNS::HNS(size_t s) : size(s), addresses(s){}

void HNS::insert(const HostName& hn, const IPAddress& ia){
  size_t str_hash = hash<string>{}(hn) % size;
  addresses[str_hash].emplace_back(hn, ia);
}
bool HNS::remove(const HostName& hn){
  size_t str_hash = hash<string>{}(hn) % size;
  auto it = remove_if(addresses[str_hash].begin(), addresses[str_hash].end(),
  [&hn] (const pair<HostName, IPAddress>& pairs) {
      return pairs.first == hn;
  });
  if(it != addresses[str_hash].end()) {
    addresses[str_hash].erase(it, addresses[str_hash].end());
    return true;
  }
  return false;
}

IPAddress HNS::lookup(const HostName& hn) const{
  size_t str_hash = hash<string>{}(hn) % size;
  auto it = find_if(addresses[str_hash].begin(), addresses[str_hash].end(),
  [&hn] (const pair<HostName, IPAddress>& pairs) {
      return pairs.first == hn;
  });
  return it != addresses[str_hash].end() ? it->second : NON_EXISTING_ADDRESS;
}
