#include <vector>

class Solution {
 public:
  auto countPyramids(const std::vector<std::vector<int>>& grid) -> int {
    int res = 0;
    std::vector<std::vector<int>> up(grid.begin(), grid.end());
    std::vector<std::vector<int>> down(grid.begin(), grid.end());
    for (size_t r = 1; r < grid.size(); ++r) {
      size_t r_inv = grid.size() - r - 1;
      for (size_t c = 1; c < grid[0].size() - 1; ++c) {
        if (grid[r][c] == 1 && grid[r - 1][c] == 1) {
          down[r][c] = std::min(down[r - 1][c - 1], down[r - 1][c + 1]) + 1;
          res += down[r][c] - 1;
        }
        if (grid[r_inv][c] == 1 && grid[r_inv + 1][c] == 1) {
          up[r_inv][c] =
              std::min(up[r_inv + 1][c - 1], up[r_inv + 1][c + 1]) + 1;
          res += up[r_inv][c] - 1;
        }
      }
    }
    return res;
  }
};
