#include <string>
#include <unordered_set>
#include <vector>

class Solution {
 public:
  bool wordBreak(std::string s, const std::vector<std::string>& wordDict) {
    const std::unordered_set<std::string> dict(wordDict.begin(),
                                               wordDict.end());

    std::vector<bool> dp(s.size() + 1, false);
    dp[0] = true;

    for (int i = 1; i <= s.size(); i++) {
      for (int j = i - 1; j >= 0; j--) {
        if (dp[j]) {
          const std::string& word = s.substr(j, i - j);
          if (dict.contains(word)) {
            dp[i] = true;
            break;
          }
        }
      }
    }

    return dp[s.size()];
  }
};
