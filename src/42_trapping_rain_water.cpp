#include <vector>

class Solution {
 public:
  int trap(std::vector<int>& height) {
    int l = 0, r = height.size() - 1;
    int res = 0;
    int l_max = 0, r_max = 0;
    while (l <= r) {
      if (height[l] <= height[r]) {
        if (height[l] >= l_max) {
          l_max = height[l];
        } else {
          res += l_max - height[l];
        }
        ++l;
      } else {
        if (height[r] >= r_max) {
          r_max = height[r];
        } else {
          res += r_max - height[r];
        }
        --r;
      }
    }
    return res;
  }
};
