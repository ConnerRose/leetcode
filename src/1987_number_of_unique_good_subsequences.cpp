#include <array>
#include <string>

class Solution {
 public:
  auto numberOfUniqueGoodSubsequences(const std::string& binary) -> int {
    int mod = 1e9;
    int dp[2] = {0, 0};
    for (char c : binary) {
      dp[c - '0'] = (dp[0] + dp[1] + c - '0') % mod;
    }
    return (dp[0] + dp[1] + binary.contains('0')) % mod;
  }
};
