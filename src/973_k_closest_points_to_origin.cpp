#include <algorithm>
#include <vector>

class Solution {
 public:
  static int dist(int x, int y) { return (x * x + y * y); }
  std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>>& points,
                                         int k) {
    auto cmp = [](auto& lhs, auto& rhs) {
      return dist(lhs[0], lhs[1]) < dist(rhs[0], rhs[1]);
    };
    nth_element(points.begin(), points.begin() + k, points.end(), cmp);
    return std::vector<std::vector<int>>(points.begin(), points.begin() + k);
  }
};
