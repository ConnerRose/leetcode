#include <vector>

class Solution {
  int mod{1000000007};
  int m{};
  int n{};

 public:
  auto helper(std::vector<std::vector<int>>& grid, int i, int j,
              std::vector<std::vector<int>>& dp, int prev) -> int {
    if (i < 0 || j < 0 || i >= m || j >= n || prev >= grid[i][j]) {
      return 0;
    }

    if (dp[i][j] != -1) {
      return dp[i][j];
    }

    int top = helper(grid, i - 1, j, dp, grid[i][j]);
    int bottom = helper(grid, i + 1, j, dp, grid[i][j]);
    int right = helper(grid, i, j + 1, dp, grid[i][j]);
    int left = helper(grid, i, j - 1, dp, grid[i][j]);

    return dp[i][j] = (1 + top + bottom + right + left) % mod;
  }

  auto countPaths(std::vector<std::vector<int>>& grid) -> int {

    m = static_cast<int>(grid.size());
    n = static_cast<int>(grid[0].size());
    if (m == 1 && n == 1) {
      return 1;
    }
    std::vector<std::vector<int>> dp(m, std::vector<int>(n, -1));

    int res = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (dp[i][j] == -1) {
          res = (res + helper(grid, i, j, dp, -1)) % mod;
        } else {
          res = (res + dp[i][j]) % mod;
        }
      }
    }

    return res;
  }
};
