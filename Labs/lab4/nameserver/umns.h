#ifndef UMNS_H
#define UMNS_H
#include <string>
#include <unordered_map>
#include "nameserverinterface.h"
using std::unordered_map;

class UMNS: public NameServerInterface {
public:
  UMNS();
  void insert(const HostName& hn, const IPAddress& ia) override;
  bool remove(const HostName& hn) override;
  IPAddress lookup(const HostName& ia) const override;
private:
  unordered_map<HostName, IPAddress> addresses;
};
#endif
