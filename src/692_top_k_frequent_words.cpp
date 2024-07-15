#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

using p = std::pair<int, std::string>;

class Solution {
 public:
  auto topKFrequent(std::vector<std::string>& words,
                    int k) -> std::vector<std::string> {
    std::unordered_map<std::string, int> freq;
    for (const std::string& word : words) {
      ++freq[word];
    }

    auto cmp = [](const p& lhs, const p& rhs) -> bool {
      if (lhs.first == rhs.first) {
        return lhs.second < rhs.second;
      }
      return lhs.first > rhs.first;
    };

    std::priority_queue<p, std::vector<p>, decltype(cmp)> pq;
    for (auto [word, count] : freq) {
      pq.emplace(count, word);
      if (pq.size() > k) {
        pq.pop();
      }
    }
    std::vector<std::string> res(k);
    int i = k;

    while (pq.size() > 0) {
      res[--i] = pq.top().second;
      pq.pop();
    }
    return res;
  }
};
