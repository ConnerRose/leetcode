#include <list>
#include <unordered_map>
#include <utility>

class LRUCache {
  size_t capacity;
  std::list<std::pair<int, int>> nodes;
  std::unordered_map<int, std::list<std::pair<int, int>>::iterator> map;

 public:
  LRUCache(size_t capacity) : capacity(capacity) {}

  auto get(int key) -> int {
    auto iter = map.find(key);
    if (iter == map.end()) {
      return -1;
    }
    int value = iter->second->second;
    nodes.erase(iter->second);
    iter->second = nodes.insert(nodes.end(), {key, value});
    return value;
  }

  auto put(int key, int value) -> void {
    auto iter = map.find(key);
    if (iter != map.end()) {
      iter->second->second = value;
      get(key);
      return;
    }
    if (nodes.size() == capacity) {
      map.erase(nodes.front().first);
      nodes.pop_front();
    }
    map[key] = nodes.insert(nodes.end(), {key, value});
  }
};
