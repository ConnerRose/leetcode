#include <algorithm>
#include <vector>

class Solution {
 public:
  auto lengthOfLIS(std::vector<int>& nums) -> int {
    std::vector<int> sub;
    for (int x : nums) {
      if (sub.empty() || sub[sub.size() - 1] < x) {
        sub.push_back(x);
      } else {
        *lower_bound(sub.begin(), sub.end(), x) = x;
      }
    }
    return static_cast<int>(sub.size());
  }
};
