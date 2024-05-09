#include <string>
#include <unordered_set>
#include <vector>

using std::string;
using std::unordered_set;
using std::vector;

class Solution {
 public:
  bool wordBreak(string s, const vector<string>& wordDict) {
    const unordered_set<string> dict(wordDict.begin(), wordDict.end());

    vector<bool> dp(s.size() + 1, false);
    dp[0] = true;

    for (int i = 1; i <= s.size(); i++) {
      for (int j = i - 1; j >= 0; j--) {
        if (dp[j]) {
          const string& word = s.substr(j, i - j);
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
