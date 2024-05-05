#include <queue>
#include <utility>
#include <vector>

using std::pair;
using std::queue;
using std::vector;

class Solution1 {
 public:
  int numIslands(vector<vector<char>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    int res = 0;
    int offsets[] = {0, 1, 0, -1, 0};
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == '0') {
          continue;
        }
        queue<pair<int, int>> q;
        q.push({i, j});
        ++res;
        while (!q.empty()) {
          auto [i, j] = q.front();
          q.pop();
          for (int k = 0; k < 4; ++k) {
            int r = i + offsets[k];
            int c = j + offsets[k + 1];
            if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == '1') {
              grid[r][c] = '0';
              q.push({r, c});
            }
          }
        }
      }
    }
    return res;
  }
};

class Solution2 {
 public:
  int numIslands(vector<vector<char>>& grid) {
    int res = 0;
    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[0].size(); ++j) {
        if (grid[i][j] == '1') {
          ++res;
          dfs(grid, i, j);
        }
      }
    }
    return res;
  }

  void dfs(vector<vector<char>>& grid, int i, int j) {
    int m = grid.size();
    int n = grid[0].size();
    if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != '1') {
      return;
    }
    grid[i][j] = '0';
    dfs(grid, i - 1, j);
    dfs(grid, i, j - 1);
    dfs(grid, i + 1, j);
    dfs(grid, i, j + 1);
  }
};
