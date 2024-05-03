#include <algorithm>
#include <vector>

using std::sort;
using std::vector;

class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());

    for (size_t i = 0; i < nums.size(); ++i) {
      int target = -nums[i];
      size_t l = i + 1;
      size_t r = nums.size() - 1;
      while (l < r) {
        int sum = nums[l] + nums[r];
        if (sum < target) {
          ++l;
        } else if (sum > target) {
          --r;
        } else {
          vector<int> triplet = {nums[i], nums[l], nums[r]};
          res.push_back(triplet);
          // Left duplicates
          while (l < r && nums[l] == triplet[1]) {
            ++l;
          }
          // Right duplicates
          while (l < r && nums[r] == triplet[2]) {
            --r;
          }
        }
      }
      // Target duplicates
      while (i + 1 < nums.size() && nums[i + 1] == nums[i]) {
        ++i;
      }
    }

    return res;
  }
};
