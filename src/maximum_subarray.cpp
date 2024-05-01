#include <vector>

using std::max;
using std::vector;

class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    int best = nums[0];
    int curr = nums[0];
    for (size_t i = 1; i < nums.size(); ++i) {
      curr = max(curr, 0) + nums[i];
      best = max(best, curr);
    }
    return best;
  }
};
