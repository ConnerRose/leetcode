#include <limits>
#include <vector>

using std::numeric_limits;
using std::vector;

class Solution {
 public:
  int search(vector<int>& nums, int target) {
    int l = 0, r = nums.size();
    while (l < r) {
      int m = (l + r) / 2;
      // If target and nums[m] on same side of pivot
      double num = (nums[m] < nums[0] == target < nums[0]) ? nums[m]
                   : target < nums[0] ? -numeric_limits<double>::infinity()
                                      : numeric_limits<double>::infinity();
      if (num < target) {
        l = m + 1;
      } else if (num > target) {
        r = m;
      } else {
        return m;
      }
    }
    return -1;
  }
};
