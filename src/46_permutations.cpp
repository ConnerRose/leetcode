#include <utility>
#include <vector>

using std::swap;
using std::vector;

class Solution {
 public:
  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> res;
    backtrack(res, nums, 0);
    return res;
  }
  void backtrack(vector<vector<int>>& res, vector<int>& nums, int start) {
    if (start == nums.size()) {
      res.push_back(nums);
    }
    for (int i = start; i < nums.size(); ++i) {
      swap(nums[start], nums[i]);
      backtrack(res, nums, start + 1);
      swap(nums[start], nums[i]);
    }
  }
};
