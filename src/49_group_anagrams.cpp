#include <string>
#include <unordered_map>
#include <vector>

class Solution {
  static auto counting_sort(const std::string& str) -> std::string {
    std::vector<int> counter(26, 0);
    for (char c : str) {
      ++counter[c - 'a'];
    }
    std::string res;
    res.reserve(str.size());
    for (size_t i = 0; i < 26; ++i) {
      res.append(counter[i], static_cast<char>(i + 'a'));
    }
    return res;
  }

 public:
  static auto groupAnagrams(std::vector<std::string>& strs)
      -> std::vector<std::vector<std::string>> {
    std::unordered_map<std::string, std::vector<std::string>> mp;
    for (const std::string& str : strs) {
      mp[counting_sort(str)].push_back(str);
    }
    std::vector<std::vector<std::string>> anagrams;
    anagrams.reserve(mp.size());
    for (const auto& [_, v] : mp) {
      anagrams.push_back(v);
    }
    return anagrams;
  }
};
