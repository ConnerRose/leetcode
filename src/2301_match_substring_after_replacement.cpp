#include <string>
#include <vector>

class Solution {
  std::vector<std::vector<bool>> set =
      std::vector<std::vector<bool>>(256, std::vector<bool>(256, false));

  auto check(const std::string& s, const std::string& sub, int pos) -> bool {
    if (pos + sub.size() > s.size()) {
      return false;
    }
    int idx = 0;
    for (int i = pos; i < pos + static_cast<int>(sub.size()); ++i) {
      if (sub[idx] == s[i] || set[sub[idx]][s[i]]) {
        ++idx;
      } else {
        return false;
      }
    }
    return true;
  }

 public:
  auto matchReplacement(std::string& s, std::string& sub,
                        std::vector<std::vector<char>>& mappings) -> bool {
    for (const auto& pair : mappings) {
      set[pair[0]][pair[1]] = true;
    }
    for (int i = 0; i < static_cast<int>(s.size()); ++i) {
      if (check(s, sub, i)) {
        return true;
      }
    }
    return false;
  }
};
