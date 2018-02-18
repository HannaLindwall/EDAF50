#include "mns.h"
#include <algorithm>

MNS::MNS() {}

void MNS::insert(const HostName& hn, const IPAddress& ia){
  addresses[hn] = ia;
}
bool MNS::remove(const HostName& hn){
  auto it = addresses.find(hn);
  if (it != addresses.end()) {
    addresses.erase(it);
    return true;
  }
  return false;
}

IPAddress MNS::lookup(const HostName& hn) const{
  auto it = addresses.find(hn);
  return it != addresses.end() ? it->second : NON_EXISTING_ADDRESS;
}
