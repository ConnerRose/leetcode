#include <algorithm>
#include <string>
#include <vector>

class Solution {
 public:
  int lengthOfLongestSubstring(std::string s) {
    int max_length = 0;
    std::vector<bool> set(256, false);
    int l = 0;
    for (int r = 0; r < s.length(); ++r) {
      char curr = s[r];
      if (!set[curr]) {
        set[curr] = true;
        max_length = std::max(max_length, r - l + 1);
      } else {
        while (set[curr]) {
          set[s[l]] = false;
          ++l;
        }
        set[curr] = true;
      }
    }
    return max_length;
  }
};
