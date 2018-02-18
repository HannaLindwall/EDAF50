#include "umns.h"
#include <algorithm>

UMNS::UMNS() {}

void UMNS::insert(const HostName& hn, const IPAddress& ia){
  addresses.insert({hn, ia});
}
bool UMNS::remove(const HostName& hn){
  auto it = addresses.find(hn);
  if (it != addresses.end()) {
    addresses.erase(it);
    return true;
  }
  return false;
}

IPAddress UMNS::lookup(const HostName& hn) const{
  auto it = addresses.find(hn);
  return it != addresses.end() ? it->second : NON_EXISTING_ADDRESS;
}
