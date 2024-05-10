#include <vector>

using std::vector;

class Solution {
 public:
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> res;
    res.reserve(1 << nums.size());
    vector<int> curr;
    curr.reserve(nums.size());
    helper(res, nums, curr, 0);
    return res;
  }

  void helper(vector<vector<int>>& res, vector<int>& nums, vector<int>& curr,
              int i) {
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
