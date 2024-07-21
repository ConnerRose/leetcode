#include <algorithm>

class Solution {
  auto f(int m, int n, int x) -> int {
    int res = 0;
    for (int i = 1; i <= m; ++i) {
      res += std::min(x / i, n);
    }
    return res;
  }

 public:
  auto findKthNumber(int m, int n, int k) -> int {
    if (m > n) {
      std::swap(m, n);
    }
    int l = 0, r = m * n, x = 0, res = 0;
    while (l <= r) {
      x = (l + r) >> 1;
      if (f(m, n, x) < k) {
        l = x + 1;
      } else {
        r = x - 1;
        res = x;
      }
    }
    return res;
  }
};
