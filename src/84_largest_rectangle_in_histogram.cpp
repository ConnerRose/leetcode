#include <vector>

class Solution {
 public:
  static auto largestRectangleArea(std::vector<int>& heights) -> int {
    int res = 0;
    heights.push_back(0);
    std::vector<int> index;

    for (int i = 0; i < static_cast<int>(heights.size()); i++) {
      while (!index.empty() && heights[index.back()] >= heights[i]) {
        int h = heights[index.back()];
        index.pop_back();

        int sidx = !index.empty() ? index.back() : -1;
        if (h * (i - sidx - 1) > res) {
          res = h * (i - sidx - 1);
        }
      }
      index.push_back(i);
    }

    return res;
  }
};
