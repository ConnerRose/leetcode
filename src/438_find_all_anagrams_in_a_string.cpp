#include <string>
#include <vector>

class Solution {
 public:
  static auto findAnagrams(const std::string& s, const std::string& p)
      -> std::vector<int> {
    if (s.size() < p.size()) {
      return {};
    }

    std::vector<int> freq(26, 0);
    std::vector<int> window(26, 0);

    //first window
    for (size_t i = 0; i < p.size(); i++) {
      freq[p[i] - 'a']++;
      window[s[i] - 'a']++;
    }

    std::vector<int> res;
    if (freq == window) {
      res.push_back(0);
    }

    for (size_t i = p.size(); i < s.size(); i++) {
      window[s[i - p.size()] - 'a']--;
      window[s[i] - 'a']++;

      if (freq == window) {
        res.push_back(static_cast<int>(i) - static_cast<int>(p.size()) + 1);
      }
    }
    return res;
  }
};
