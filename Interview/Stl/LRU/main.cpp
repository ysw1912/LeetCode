#include <list>
#include <unordered_map>

#include <cassert>

#include "utils.h"

using namespace std;

class LRUCache {
 public:
  explicit LRUCache(int capacity) : capacity_(capacity) {}

  int get(int key) {
    if (dict_.count(key)) {
      list_.splice(list_.begin(), list_, dict_[key]);
      cout << "Get " << key << "->" << dict_[key]->second << ": " << list_ << endl;
      return dict_[key]->second;
    }
    return -1;
  }

  void put(int key, int value) {
    if (dict_.count(key)) {
      dict_[key]->second = value;
      list_.splice(list_.begin(), list_, dict_[key]);
    } else {
      dict_[key] = list_.insert(list_.begin(), make_pair(key, value));
      if (list_.size() > capacity_) {
        dict_.erase(list_.back().first);
        list_.pop_back();
      }
    }
    cout << "Put " << key << "->" << value << ": " << list_ << endl;
  }

 private:
  int capacity_;
  list<pair<int, int>> list_;
  unordered_map<int, list<pair<int, int>>::iterator> dict_;
};

int main() {
  auto* cache = new LRUCache(2);
  cache->put(1, 0);             // Cache is {1: 0}.
  cache->put(2, 2);             // Cache is {2: 2, 1: 0}.
  assert(cache->get(1) == 0);   // Cache is {1: 0, 2: 2}.
  cache->put(3, 3);             // Evicts key 2, cache is {1: 0, 3: 3}.
  assert(cache->get(2) == -1);  // Not found.
  cache->put(4, 4);             // Evicts key 1, cache is {3: 3, 4: 4}.
  assert(cache->get(1) == -1);  // Not found.
  assert(cache->get(3) == 3);   // Cache is {4: 4, 3: 3}.
  assert(cache->get(4) == 4);
  delete cache;
}
