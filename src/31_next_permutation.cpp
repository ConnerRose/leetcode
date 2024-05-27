#include <algorithm>
#include <vector>

class Solution {
 public:
  static auto nextPermutation(std::vector<int>& nums) -> void {
    int n = static_cast<int>(nums.size());
    int k = 0;
    int l = 0;
    for (k = n - 2; k >= 0; k--) {
      if (nums[k] < nums[k + 1]) {
        break;
      }
    }
    if (k < 0) {
      std::reverse(nums.begin(), nums.end());
      return;
    }
    for (l = n - 1; l > k; l--) {
      if (nums[l] > nums[k]) {
        break;
      }
    }
    std::swap(nums[k], nums[l]);
    std::reverse(nums.begin() + k + 1, nums.end());
  }
};
