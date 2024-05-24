#include <list>
#include <unordered_map>
#include <utility>

class LRUCache {
  size_t capacity;
  std::unordered_map<int, std::list<std::pair<int, int>>::iterator> map;
  std::list<std::pair<int, int>> nodes;

 public:
  LRUCache(size_t capacity) : capacity(capacity) {}

  auto get(int key) -> int {
    if (!map.contains(key)) {
      return -1;
    }
    // move the node corresponding to key to front
    nodes.splice(nodes.begin(), nodes, map[key]);
    return map[key]->second;
  }

  void put(int key, int value) {
    if (map.contains(key)) {
      //move the node corresponding to key to front
      nodes.splice(nodes.begin(), nodes, map[key]);
      map[key]->second = value;
      return;
    }
    if (map.size() == capacity) {
      int keyToDel = nodes.back().first;
      nodes.pop_back();
      map.erase(keyToDel);
    }
    nodes.emplace_front(key, value);
    map[key] = nodes.begin();
  }
};
