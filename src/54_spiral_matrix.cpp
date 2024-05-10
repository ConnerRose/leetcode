#include <vector>

using std::vector;

class Solution {
 public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    int top = 0, bottom = m - 1;
    int left = 0, right = n - 1;
    vector<int> res;
    res.reserve(n * m);
    while (res.size() < n * m) {
      for (int j = left; j <= right && res.size() < n * m; j++) {
        res.push_back(matrix[top][j]);
      }
      for (int i = top + 1; i <= bottom - 1 && res.size() < n * m; i++) {
        res.push_back(matrix[i][right]);
      }
      for (int j = right; j >= left && res.size() < n * m; j--) {
        res.push_back(matrix[bottom][j]);
      }
      for (int i = bottom - 1; i >= top + 1 && res.size() < n * m; i--) {
        res.push_back(matrix[i][left]);
      }
      ++left, --right, ++top, --bottom;
    }
    return res;
  }
};
