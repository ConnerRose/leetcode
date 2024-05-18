#include <cstdint>
#include <utility>
#include <vector>

class Solution {
 public:
  void sortColors(std::vector<int>& nums) {
    int16_t i = 0, j = 0, k = nums.size() - 1;
    while (j <= k) {
      if (nums[j] == 0) {
        std::swap(nums[i], nums[j]);
        ++i;
        ++j;
      } else if (nums[j] == 2) {
        std::swap(nums[j], nums[k]);
        --k;
      } else {
        ++j;
      }
    }
  }
};
