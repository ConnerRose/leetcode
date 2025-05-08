#include <map>
#include <unordered_map>
#include <utility>
#include <vector>

class Allocator {
  std::unordered_map<int, std::vector<std::pair<int, int>>> allocated;
  std::map<int, int> available;

 public:
  Allocator(int n) { available[0] = n; }

  auto allocate(int size, int mID) -> int {
    for (auto iter = available.begin(); iter != available.end(); ++iter) {
      if (iter->second < size) {
        continue;
      }
      auto [start, interval_size] = *iter;
      available.erase(iter);
      allocated[mID].emplace_back(start, size);
      if (interval_size > size) {
        available[start + size] = interval_size - size;
      }
      return start;
    }
    return -1;
  }

  auto free(int mID) -> int {
    int res = 0;
    auto iter = allocated.find(mID);
    if (iter == allocated.end()) {
      return res;
    }
    for (auto [idx, interval_size] : iter->second) {
      auto freed = available.emplace(idx, interval_size).first;
      if (freed != available.begin()) {
        if (auto prev = std::prev(freed); prev->first + prev->second == idx) {
          prev->second += interval_size;
          available.erase(freed);
          freed = prev;
        }
      }
      if (std::next(freed) != available.end()) {
        if (auto next = std::next(freed); idx + interval_size == next->first) {
          freed->second += next->second;
          available.erase(next);
        }
      }
      res += interval_size;
    }
    allocated.erase(iter);
    return res;
  }
};
