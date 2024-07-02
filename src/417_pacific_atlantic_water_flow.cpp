#include <vector>

using std::vector;

class Solution {
 public:
  int m, n;
  std::vector<std::vector<bool>> atlantic, pacific;
  std::vector<std::vector<int>> ans;

  auto pacificAtlantic(std::vector<std::vector<int>>& mat)
      -> std::vector<std::vector<int>> {
    if (mat.size() == 0) {
      return ans;
    }

    m = static_cast<int>(mat.size());
    n = static_cast<int>(mat[0].size());
    atlantic = std::vector<std::vector<bool>>(m, std::vector<bool>(n, false));
    pacific = std::vector<std::vector<bool>>(m, std::vector<bool>(n, false));

    for (int i = 0; i < m; i++) {
      dfs(mat, pacific, i, 0);
      dfs(mat, atlantic, i, n - 1);
    }
    for (int i = 0; i < n; i++) {
      dfs(mat, pacific, 0, i);
      dfs(mat, atlantic, m - 1, i);
    }
    return ans;
  }

  void dfs(std::vector<std::vector<int>>& mat,
           std::vector<std::vector<bool>>& visited, int i, int j) {
    if (visited[i][j]) {
      return;
    }
    visited[i][j] = true;
    if (atlantic[i][j] && pacific[i][j]) {
      ans.push_back(std::vector<int>{i, j});
    }

    if (i + 1 < m && mat[i + 1][j] >= mat[i][j]) {
      dfs(mat, visited, i + 1, j);
    }
    if (i - 1 >= 0 && mat[i - 1][j] >= mat[i][j]) {
      dfs(mat, visited, i - 1, j);
    }
    if (j + 1 < n && mat[i][j + 1] >= mat[i][j]) {
      dfs(mat, visited, i, j + 1);
    }
    if (j - 1 >= 0 && mat[i][j - 1] >= mat[i][j]) {
      dfs(mat, visited, i, j - 1);
    }
  }
};
