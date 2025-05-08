#include <algorithm>
#include <bitset>
#include <unordered_map>
#include <vector>

class Solution {
  static constexpr int MAX_WIDTH = 300;

 public:
  auto maxEqualRowsAfterFlips(
      const std::vector<std::vector<int>>& matrix) noexcept -> int {
    std::unordered_map<std::bitset<MAX_WIDTH>, int> counter;
    int res = 0;
    for (const auto& row : matrix) {
      std::bitset<MAX_WIDTH> bs;
      for (size_t i = 0; i < row.size(); ++i) {
        bs.set(i, row[i] == row[0]);
      }
      res = std::max(res, ++counter[bs]);
    }
    return res;
  }
};
