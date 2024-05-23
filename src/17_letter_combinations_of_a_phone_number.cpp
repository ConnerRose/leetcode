#include <string>
#include <utility>
#include <vector>

class Solution {
 public:
  static auto letterCombinations(const std::string& digits)
      -> std::vector<std::string> {
    if (digits.empty()) {
      return {};
    }

    const std::vector<std::string_view> map{
        "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    std::vector<std::string> res;
    res.emplace_back("");

    for (const char digit : digits) {
      std::vector<std::string> tmp;
      for (const char candidate : map[digit - '0']) {
        for (const std::string& s : res) {
          tmp.push_back(s + candidate);
        }
      }
      std::swap(res, tmp);
    }
    return res;
  }
};
