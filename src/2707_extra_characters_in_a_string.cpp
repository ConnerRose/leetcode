#include <array>
#include <string>
#include <vector>

class Solution {
 public:
  auto minExtraChar(const std::string& s,
                    std::vector<std::string>& dictionary) -> int {
    std::array<int, 51> dp{0};
    for (size_t i = s.size() - 1; i >= 0; --i) {
      dp[i] = 1 + dp[i + 1];
      for (const auto& word : dictionary) {
        if (i + word.size() <= s.size() &&
            s.compare(i, word.size(), word) == 0) {
          dp[i] = std::min(dp[i], dp[i + word.size()]);
        }
      }
    }
    return dp[0];
  }
};
