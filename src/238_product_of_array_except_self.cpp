#include <vector>

class Solution {
 public:
  std::vector<int> productExceptSelf(std::vector<int>& nums) {
    int n = nums.size();
    std::vector<int> res(n);
    int prod = 1;
    for (int i = 0; i < n; i++) {
      res[i] = prod;
      prod *= nums[i];
    }
    prod = 1;
    for (int i = n - 1; i >= 0; i--) {
      res[i] *= prod;
      prod *= nums[i];
    }
    return res;
  }
};
