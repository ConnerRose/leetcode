#include <array>
#include <string>
#include <vector>

class Solution {
 public:
  auto addSpaces(std::string& s, const std::vector<int>& spaces)
      -> std::string {
    const int N = static_cast<int>(s.size() + spaces.size());
    int diff = static_cast<int>(spaces.size()) - 1;
    s.resize(N);
    for (int i = N - 1; i >= 0 && diff >= 0; --i) {
      std::array<char, 2> arr = {s[std::max(0, i - diff - 1)], ' '};
      s[i] = arr[static_cast<int>(i - diff == spaces[diff])];
      diff -= static_cast<int>(i - diff == spaces[diff]);
    }
    return s;
  }
};
