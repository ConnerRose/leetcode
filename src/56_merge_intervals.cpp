#include <algorithm>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> merge(
      std::vector<std::vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    std::vector<std::vector<int>> res;
    for (const std::vector<int>& interval : intervals) {
      if (res.empty() || res.back()[1] < interval[0]) {
        res.push_back(interval);
      } else {
        res.back()[1] = std::max(res.back()[1], interval[1]);
      }
    }
    return res;
  }
};
