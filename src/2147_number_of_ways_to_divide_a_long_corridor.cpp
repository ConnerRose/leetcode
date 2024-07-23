#include <string>
#include <vector>

class Solution {
 public:
  auto numberOfWays(const std::string& corridor) -> int {
    std::vector<int> pos;
    for (int i = 0; i < static_cast<int>(corridor.size()); ++i) {
      if (corridor[i] == 'S') {
        pos.push_back(i);
      }
    }
    if (pos.size() % 2 == 1 || pos.size() == 0) {
      return 0;
    }
    long long res = 1;
    int prev = pos[1];
    for (int i = 2; i < static_cast<int>(pos.size()); i += 2) {
      res = (res * (pos[i] - prev)) % 1000000007;
      prev = pos[i + 1];
    }
    return res;
  }
};
