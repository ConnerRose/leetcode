#include <vector>

using std::min;
using std::vector;

class Solution {
 public:
  vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size(), MAX = m + n;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (mat[i][j] == 0)
          continue;
        int top = i - 1 >= 0 ? mat[i - 1][j] : MAX;
        int left = j - 1 >= 0 ? mat[i][j - 1] : MAX;
        mat[i][j] = min(top, left) + 1;
      }
    }
    for (int i = m - 1; i >= 0; i--) {
      for (int j = n - 1; j >= 0; j--) {
        if (mat[i][j] == 0)
          continue;
        int bottom = i + 1 < m ? mat[i + 1][j] : MAX;
        int right = j + 1 < n ? mat[i][j + 1] : MAX;
        mat[i][j] = min(mat[i][j], min(bottom, right) + 1);
      }
    }
    return mat;
  }
};
