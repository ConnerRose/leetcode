#include <array>
#include <queue>
#include <string>
#include <vector>

class Solution {
 public:
  std::array<std::array<int, 2000>, 26> locations{};
  std::array<int, 26> count{0};
  std::array<bool, 2000> seen{false};
  using p = std::pair<int, int>;
  static constexpr auto CMP = [](const p& lhs, const p& rhs) {
    return lhs.first > rhs.first ||
           (lhs.first == rhs.first && lhs.second < rhs.second);
  };
  std::array<p, 1> dummy = {{{0, 0}}};
  std::priority_queue<p, std::vector<p>, decltype(CMP)> pq{dummy.begin(),
                                                           dummy.end()};

  constexpr Solution() = default;

  constexpr static auto check(const std::string& s, int l, int r) -> bool {
    while (l < r) {
      if (s[l++] != s[r--]) {
        return false;
      }
    }
    return true;
  }

  auto minCut(const std::string& s) -> int {
    int n = static_cast<int>(s.size());
    for (int i = n - 1; i >= 0; --i) {
      locations[s[i] - 'a'][count[s[i] - 'a']++] = i;
    }
    while (!pq.empty()) {
      auto [cuts, idx] = pq.top();
      pq.pop();
      for (int i = 0; i < count[s[idx] - 'a']; ++i) {
        int idx2 = locations[s[idx] - 'a'][i];
        if (seen[idx2]) {
          continue;
        }
        if (check(s, idx, idx2)) {
          if (idx2 + 1 == n) {
            return cuts;
          }
          pq.emplace(cuts + 1, idx2 + 1);
          seen[idx2] = true;
        }
      }
    }
    return -1;
  }
};
