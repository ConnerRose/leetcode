#include <string>

class Solution {
 public:
  static auto canMakeSubsequence(std::string& s1, std::string& s2) -> bool {
    size_t j = 0;
    size_t n = s1.size();
    size_t m = s2.size();
    for (size_t i = 0; i < n && j < m; ++i) {
      if ((s2[j] + 26 - s1[i]) % 26 <= 1) {
        ++j;
      }
    }
    return j == m;
  }
};
