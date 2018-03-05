#ifndef AV_H
#define AV_H
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

template<typename Key , typename Value >
class AV {
public:
  using key_type = Key;
	using mapped_type = Value;
	using value_type = std::pair<Key, Value>;
  using iterator = typename std::vector<value_type>::iterator;

  iterator begin(){return v.begin();};
  iterator end(){return v.end();};

  iterator find(const key_type& key);

  std::pair<iterator, bool> insert(const value_type& val);
private:
  std::vector<value_type > v;
  // man checkar var man ska sätta in för att få en unik key/month
  static bool findPlace(const value_type& pair, const key_type& insert_month) {
    return pair.first < insert_month;
  }
};
// returnera ett par med en iterator och bool i sig. bool säger om insert gick bra eller inte
// iom att AV är en template måste man typename AV framför iteratorn och AV::
// framför insert
template<typename Key, typename Value>
std::pair<typename AV<Key, Value>::iterator, bool>
AV<Key, Value>::insert(const value_type& pair){
  //lower_bound hittar platsen innan samma månad, sätt in där
  auto it = lower_bound(v.begin(), v.end(), pair.first, findPlace);
  // om nyckeln existerar returnera false, i och med att man vill ha unika
  // nycklar - det visas då att man inte är i slutet av v och key i it är
  // samma som för valuet
  if(it != v.end() && it->first == pair.first) {
    return make_pair(it, false);
  }
  //sätt in på positionen för elementet innan it, it->first och it->second har
  //inga värden, returnerar false, dvs. det finns ingen annan key, den är unik
  v.insert(it, pair);
  return make_pair(it, true);
}
// returnera ett par med en iterator.
template<typename Key, typename Value>
typename AV<Key, Value>::iterator
AV<Key, Value>::find(const key_type& month) {
  //om jag använder lower_bound behöver jag inte söka mer än nödvändigt
  auto it = lower_bound(v.begin(), v.end(), month, findPlace);
  //it kan ha hittat något I guess, men så extrakollar man
  if(it == v.end() || it->first != month) {
    return v.end();
  }
  return it;
}
#endif
