#include <algorithm>
#include <map>
#include <vector>

class SummaryRanges {
  std::map<int, int> m;

 public:
  auto addNum(int value) -> void {
    auto iter = m.lower_bound(value);
    int start = value;
    int end = value;
    if (iter != m.begin() && std::prev(iter)->second + 1 >= start) {
      iter = std::prev(iter);
    }
    while (iter != m.end() && end + 1 >= iter->first) {
      start = std::min(start, iter->first);
      end = std::max(end, iter->second);
      iter = m.erase(iter);
    }
    m.insert(iter, {start, end});
  }

  auto getIntervals() -> std::vector<std::vector<int>> {
    std::vector<std::vector<int>> res;
    res.reserve(m.size());
    for (auto [start, end] : m) {
      res.push_back({start, end});
    }
    return res;
  }
};
