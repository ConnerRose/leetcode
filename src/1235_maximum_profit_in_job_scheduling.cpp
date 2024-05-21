#include <algorithm>
#include <map>
#include <tuple>
#include <utility>
#include <vector>

class Solution {
 public:
  int jobScheduling(std::vector<int>& start_time, std::vector<int>& end_time,
                    std::vector<int>& profit) {
    int n = start_time.size();
    std::vector<std::tuple<int, int, int>> jobs;
    jobs.reserve(n);
    for (int i = 0; i < n; ++i) {
      jobs.push_back({end_time[i], start_time[i], profit[i]});
    }
    std::sort(jobs.begin(), jobs.end());

    // dp[time] = max profit up to and including time
    std::map<int, int> dp = {{0, 0}};

    for (auto [end, start, profit] : jobs) {
      // prev(dp.upper_bound(start)) is last entry up to start
      int curr = prev(dp.upper_bound(start))->second + profit;
      if (curr > dp.rbegin()->second) {
        dp[end] = curr;
      }
    }

    return dp.rbegin()->second;
  }
};
