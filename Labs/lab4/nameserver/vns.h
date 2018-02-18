#ifndef VNS_H
#define VNS_H
#include <iostream>
#include <string>
#include <vector>
#include "nameserverinterface.h"
using std::vector;
using std::pair;

class VNS: public NameServerInterface {
public:
  VNS();
  void insert(const HostName& hn, const IPAddress& ia) override;
  bool remove(const HostName& hn) override;
  IPAddress lookup(const HostName& ia) const override;
private:
  vector<pair<HostName, IPAddress>> addresses;
};
#endif
