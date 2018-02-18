#include "vns.h"
#include <algorithm>
using std::string;
using std::find_if;

VNS::VNS() {}

void VNS::insert(const HostName& hn, const IPAddress& ia){
  addresses.push_back(make_pair(hn, ia));
}
bool VNS::remove(const HostName& hn){
  auto it = remove_if(addresses.begin(), addresses.end(),
  [hn] (const pair<HostName, IPAddress>& pairs) {
      return pairs.first == hn;
  });
  if(it != addresses.end()) {
    addresses.erase(it, addresses.end());
    return true;
  }
  return false;
}

IPAddress VNS::lookup(const HostName& hn) const{
  auto it = find_if(addresses.begin(), addresses.end(),
  [hn] (const pair<HostName, IPAddress>& pairs){
      return pairs.first == hn;
    } );
  return it != addresses.end() ? it->second : NON_EXISTING_ADDRESS;
}
