#include <bitset>
#include <numeric>
#include <vector>

class Solution {
 public:
  bool canPartition(std::vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 == 1) {
      return false;
    }
    int half = sum / 2;
    // Each bit represents whether or not that sum can be reached
    // 10001 is maximum possible sum / 2
    std::bitset<10001> dp(1);
    for (int num : nums) {
      dp |= dp << num;
    }
    return dp[half];
  }
};
