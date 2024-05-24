#include <algorithm>
#include <utility>
#include <vector>

class Solution {
 public:
  static auto rob(std::vector<int>& nums) -> int {
    int prev1 = 0;
    int prev2 = 0;
    for (int num : nums) {
      std::tie(prev1, prev2) =
          std::make_pair(std::max(prev2 + num, prev1), prev1);
    }
    return prev1;
  }
};
