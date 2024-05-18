#include <algorithm>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> insert(std::vector<std::vector<int>>& intervals,
                                       std::vector<int>& new_interval) {
    // Binary search for insert position
    auto insert_pos =
        lower_bound(intervals.begin(), intervals.end(), new_interval);
    intervals.insert(insert_pos, new_interval);
    std::vector<std::vector<int>> res;
    // Continually merge intervals as we insert into result array
    for (std::vector<int>& interval : intervals) {
      if (res.empty() || res.back()[1] < interval[0]) {
        res.push_back(interval);
      } else {
        res.back()[1] = std::max(res.back()[1], interval[1]);
      }
    }
    return res;
  }
};
