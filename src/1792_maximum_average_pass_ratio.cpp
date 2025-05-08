#include <queue>
#include <vector>

class Solution {
 public:
  auto maxAverageRatio(const std::vector<std::vector<int>>& classes,
                       int extraStudents) -> double {
    auto cmp = [](const std::pair<int, int>& l,
                  const std::pair<int, int>& r) -> bool {
      return static_cast<long long>(l.second - l.first) * r.second *
                 (r.second + 1) <
             static_cast<long long>(r.second - r.first) * l.second *
                 (l.second + 1);
    };
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                        decltype(cmp)>
        pq;
    for (const auto& c : classes) {
      pq.emplace(c[0], c[1]);
    }
    for (int i = 0; i < extraStudents; ++i) {
      auto p = pq.top();
      pq.pop();
      ++p.first;
      ++p.second;
      pq.push(p);
    }
    double sum = 0;
    while (!pq.empty()) {
      auto p = pq.top();
      pq.pop();
      sum += static_cast<double>(p.first) / p.second;
    }
    return sum / static_cast<float>(classes.size());
  }
};
