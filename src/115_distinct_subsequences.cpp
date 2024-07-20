#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
 public:
  auto numDistinct(const string& s, const string& t) -> int {
    vector<vector<long>> dp(t.size() + 1, vector<long>(s.size() + 1, 0));
    for (size_t j = 0; j < s.size(); ++j) {
      dp[0][j] = 1;
    }
    for (size_t i = 0; i < t.size(); ++i) {
      for (size_t j = 0; j < s.size(); ++j) {
        dp[i + 1][j + 1] = dp[i + 1][j] + (t[i] == s[j] ? dp[i][j] : 0);
      }
    }
    return dp[t.size()][s.size()];
  }
};
