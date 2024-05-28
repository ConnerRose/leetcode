#include <algorithm>
#include <vector>

class Solution {
 public:
  static auto maxProduct(std::vector<int>& nums) -> int {
    int res = nums[0];
    int l = 0;
    int r = 0;
    for (size_t i = 0; i < nums.size(); i++) {
      l = (l != 0 ? l : 1) * nums[i];
      r = (r != 0 ? r : 1) * nums[nums.size() - 1 - i];
      res = std::max(res, std::max(l, r));
    }
    return res;
  }
};
