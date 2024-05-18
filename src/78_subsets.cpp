#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
    std::vector<std::vector<int>> res;
    res.reserve(1 << nums.size());
    std::vector<int> curr;
    curr.reserve(nums.size());
    helper(res, nums, curr, 0);
    return res;
  }

  void helper(std::vector<std::vector<int>>& res, std::vector<int>& nums,
              std::vector<int>& curr, int i) {
    if (i == nums.size()) {
      res.push_back(curr);
      return;
    }
    curr.push_back(nums[i]);
    helper(res, nums, curr, i + 1);
    curr.pop_back();
    helper(res, nums, curr, i + 1);
  }
};
