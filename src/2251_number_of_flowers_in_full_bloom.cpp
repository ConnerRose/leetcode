#include <algorithm>
#include <vector>

class Solution {
 public:
  auto fullBloomFlowers(std::vector<std::vector<int>>& flowers,
                        std::vector<int>& people) -> std::vector<int> {
    std::vector<int> start;
    std::vector<int> end;
    for (auto& t : flowers) {
      start.push_back(t[0]), end.push_back(t[1]);
    }
    std::sort(start.begin(), start.end());
    std::sort(end.begin(), end.end());
    std::vector<int> res;
    res.reserve(people.size());
    for (int t : people) {
      int started =
          std::upper_bound(start.begin(), start.end(), t) - start.begin();
      int ended = std::lower_bound(end.begin(), end.end(), t) - end.begin();
      res.push_back(started - ended);
    }
    return res;
  }
};
