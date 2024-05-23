#include <algorithm>
#include <vector>

class Solution {
 public:
  static auto maxArea(std::vector<int>& height) -> int {
    int l = 0;
    int r = static_cast<int>(height.size()) - 1;
    int res = 0;
    while (l <= r) {
      res = std::max(res, (r - l) * std::min(height[l], height[r]));
      if (height[l] < height[r]) {
        ++l;
      } else {
        --r;
      }
    }
    return res;
  }
};
