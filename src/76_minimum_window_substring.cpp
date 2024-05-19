#include <string>
#include <unordered_map>

class Solution {
 public:
  std::string minWindow(std::string s, std::string t) {
    std::unordered_map<char, int> need;
    for (char c : t) {
      ++need[c];
    }
    int missing = t.size();
    int start = 0, min_length = INT_MAX;
    int l = 0;
    for (int r = 1; r <= s.size(); ++r) {
      if (need[s[r - 1]] > 0) {
        --missing;
      }
      --need[s[r - 1]];
      if (missing == 0) {
        while (l < r && need[s[l]] < 0) {
          ++need[s[l]];
          ++l;
        }
        if (r - l < min_length) {
          start = l;
          min_length = r - l;
        }
      }
    }
    return min_length == INT_MAX ? "" : s.substr(start, min_length);
  }
};
