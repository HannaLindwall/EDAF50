#ifndef MNS_H
#define MNS_H
#include <string>
#include <map>
#include "nameserverinterface.h"
using std::map;

class MNS: public NameServerInterface {
public:
  void insert(const HostName& hn, const IPAddress& ia) override;
  bool remove(const HostName& hn) override;
  IPAddress lookup(const HostName& ia) const override;
private:
  map<HostName, IPAddress> addresses;
};
#endif
