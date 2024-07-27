#include <algorithm>
#include <vector>

class Solution {
 public:
  static auto maximalRectangle(std::vector<std::vector<char>>& matrix) -> int {
    if (matrix.empty()) {
      return 0;
    }
    int n = static_cast<int>(matrix.size());
    int m = static_cast<int>(matrix[0].size());
    std::vector<int> left(m, 0);
    std::vector<int> right(m, m);
    std::vector<int> height(m, 0);
    int res = 0;
    for (int i = 0; i < n; i++) {
      int cur_left = 0;
      int cur_right = m;
      for (int j = 0; j < m; j++) {
        if (matrix[i][j] == '1') {
          height[j]++;
        } else {
          height[j] = 0;
        }
      }
      for (int j = 0; j < m; j++) {
        if (matrix[i][j] == '1') {
          left[j] = std::max(left[j], cur_left);
        } else {
          left[j] = 0;
          cur_left = j + 1;
        }
      }
      for (int j = m - 1; j >= 0; j--) {
        if (matrix[i][j] == '1') {
          right[j] = std::min(right[j], cur_right);
        } else {
          right[j] = m;
          cur_right = j;
        }
      }
      for (int j = 0; j < m; j++) {
        res = std::max(res, (right[j] - left[j]) * height[j]);
      }
    }
    return res;
  }
};
