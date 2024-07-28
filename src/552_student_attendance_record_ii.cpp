#include <vector>

class Solution {
 public:
  static auto checkRecord(int n) -> int {
    constexpr int MOD = 1e9 + 7;
    std::vector<std::vector<std::vector<int>>> dp(
        n + 1, std::vector<std::vector<int>>(2, std::vector<int>(3, 0)));
    dp[0] = {{1, 1, 1}, {1, 1, 1}};
    // dp[i][j][k] = # sequences of length i with at most j absences and at most
    //               k trailing lates
    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j < 2; ++j) {
        for (int k = 0; k < 3; ++k) {
          int val = dp[i - 1][j][2];
          if (j > 0) {
            val = (val + dp[i - 1][j - 1][2]) % MOD;
          }
          if (k > 0) {
            val = (val + dp[i - 1][j][k - 1]) % MOD;
          }
          dp[i][j][k] = val;
        }
      }
    }
    return dp[n][1][2];
  }
};
