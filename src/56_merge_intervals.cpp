#include <algorithm>
#include <vector>

using std::max;
using std::vector;

class Solution {
 public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> res;
    for (const vector<int>& interval : intervals) {
      if (res.empty() || res.back()[1] < interval[0]) {
        res.push_back(interval);
      } else {
        res.back()[1] = max(res.back()[1], interval[1]);
      }
    }
    return res;
  }
};
