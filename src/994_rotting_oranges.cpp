#include <queue>
#include <utility>
#include <vector>

class Solution {
 public:
  int orangesRotting(std::vector<std::vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size(), fresh = 0;
    std::queue<std::pair<int, int>> q;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 2) {
          q.push({i, j});
        } else if (grid[i][j] == 1) {
          ++fresh;
        }
      }
    }
    int res = 0, dir[] = {0, 1, 0, -1, 0};
    while (!q.empty() && fresh > 0) {
      ++res;
      int size = q.size();
      while (size--) {
        auto [i, j] = q.front();
        q.pop();
        for (int k = 0; k < 4; ++k) {
          int r = i + dir[k];
          int c = j + dir[k + 1];
          if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == 1) {
            --fresh;
            grid[r][c] = 2;
            q.push({r, c});
          }
        }
      }
    }
    return fresh == 0 ? res : -1;
  }
};
