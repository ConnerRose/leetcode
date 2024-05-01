#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> insert(vector<vector<int>>& intervals,
                             vector<int>& new_interval) {
    // Binary search for insert position
    auto insert_pos =
        lower_bound(intervals.begin(), intervals.end(), new_interval);
    intervals.insert(insert_pos, new_interval);
    vector<vector<int>> res;
    // Continually merge intervals as we insert into result array
    for (vector<int>& interval : intervals) {
      if (res.empty() || res.back()[1] < interval[0]) {
        res.push_back(interval);
      } else {
        res.back()[1] = max(res.back()[1], interval[1]);
      }
    }
    return res;
  }
};
