#ifndef HSN_H
#define HSN_H
#include "nameserverinterface.h"
#include <iostream>
#include <string>
#include <vector>
using std::size_t;
using std::vector;
using std::pair;

class HNS: public NameServerInterface {
public:
  HNS(size_t size);
  void insert(const HostName& hn, const IPAddress& ai) override;
  bool remove(const HostName& hn) override;
  IPAddress lookup(const HostName& hn) const override;
private:
  size_t size;
  vector<vector<pair<HostName, IPAddress>>> addresses;
};
#endif
