#include <array>
#include <numeric>
#include <string>

class Solution {
 public:
  auto distinctSubseqII(const std::string& s) -> long {
    std::array<long, 26> dp = {0L};
    long mod = 1e9 + 7;
    for (char c : s) {
      dp[c - 'a'] = (std::accumulate(dp.begin(), dp.end(), 0L) + 1) % mod;
    }
    return std::accumulate(dp.begin(), dp.end(), 0L) % mod;
  }
};
