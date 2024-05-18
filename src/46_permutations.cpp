#include <utility>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> permute(std::vector<int>& nums) {
    std::vector<std::vector<int>> res;
    backtrack(res, nums, 0);
    return res;
  }
  void backtrack(std::vector<std::vector<int>>& res, std::vector<int>& nums,
                 int start) {
    if (start == nums.size()) {
      res.push_back(nums);
    }
    for (int i = start; i < nums.size(); ++i) {
      std::swap(nums[start], nums[i]);
      backtrack(res, nums, start + 1);
      std::swap(nums[start], nums[i]);
    }
  }
};
