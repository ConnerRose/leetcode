#include <algorithm>
#include <vector>

class Solution {
 public:
  int coinChange(std::vector<int>& coins, int amount) {
    int dp[amount + 1];
    dp[0] = 0;
    sort(coins.begin(), coins.end());
    for (int i = 1; i < amount + 1; ++i) {
      dp[i] = INT_MAX;
      for (int coin : coins) {
        if (i - coin < 0) {
          break;
        }
        if (dp[i - coin] != INT_MAX) {
          dp[i] = std::min(dp[i], dp[i - coin] + 1);
        }
      }
    }
    return dp[amount] == INT_MAX ? -1 : dp[amount];
  }
};
