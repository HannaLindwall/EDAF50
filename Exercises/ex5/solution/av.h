#ifndef AV_H
#define AV_H

#include <vector>
#include <utility>
#include <algorithm>

template<typename Key, typename T>
class AV {
public:
	using key_type = Key;
	using mapped_type = T;
	using value_type = std::pair<Key, T>;
	using iterator = typename std::vector<value_type>::iterator;

	iterator begin() { return v.begin(); }
	iterator end() { return v.end(); }

	AV() {}
	std::pair<iterator, bool> insert(const value_type& val);
	iterator find(const key_type& k);
private:
	std::vector<value_type > v;
	static bool first_less(const value_type& p, const key_type& s) {
		return p.first < s;
	}
};

template<typename Key, typename T>
std::pair<typename AV<Key, T>::iterator, bool>
AV<Key, T>::insert(const value_type& val) {
	auto it = lower_bound(v.begin(), v.end(), val.first, first_less);
	if (it != v.end() && it->first == val.first) {
		return make_pair(it, false);
	}
	v.insert(it, val);
	return make_pair(it, true);
}

template<typename Key, typename T>
typename AV<Key, T>::iterator
AV<Key, T>::find(const key_type& k) {
	auto it = lower_bound(v.begin(), v.end(), k, first_less);
	if (it == v.end() || it->first != k) {
		return v.end();
	}
	return it;
}

#endif
