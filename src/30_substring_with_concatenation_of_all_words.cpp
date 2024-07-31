#include <string>
#include <unordered_map>
#include <vector>

class Solution {
 public:
  static auto findSubstring(const std::string& s,
                            std::vector<std::string>& words)
      -> std::vector<int> {
    std::vector<int> res;
    int n = static_cast<int>(s.size());
    int word_count = static_cast<int>(words.size());
    std::unordered_map<std::string, int> counts;
    for (int i = 0; i < word_count; ++i) {
      ++counts[words[i]];
    }
    int word_length = static_cast<int>(words[0].size());
    for (int i = 0; i < word_length; ++i) {
      int left = i;
      int count = 0;
      std::unordered_map<std::string, int> seen;
      for (int j = i; j <= n - word_length; j += word_length) {
        std::string str = s.substr(j, word_length);
        if (!counts.contains(str)) {
          seen.clear();
          count = 0;
          left = j + word_length;
          continue;
        }
        if (++seen[str] <= counts[str]) {
          if (++count == word_count) {
            res.push_back(left);
            --seen[s.substr(left, word_length)];
            --count;
            left += word_length;
          }
          continue;
        }
        while (seen[str] > counts[str]) {
          std::string leftmost = s.substr(left, word_length);
          if (--seen[leftmost] < counts[leftmost]) {
            --count;
          }
          left += word_length;
        }
      }
    }

    return res;
  }
};
