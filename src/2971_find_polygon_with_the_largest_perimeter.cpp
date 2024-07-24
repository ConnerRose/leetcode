#include <algorithm>
#include <vector>

class Solution {
 public:
  auto largestPerimeter(std::vector<int>& nums) -> long long {
    std::sort(nums.begin(), nums.end());
    long long res = -1;
    long long cur = 0;
    for (int num : nums) {
      if ((cur += num) > num * 2) {
        res = cur;
      }
    }
    return res;
  }
};
