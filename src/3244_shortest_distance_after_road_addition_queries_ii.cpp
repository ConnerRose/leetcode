#include <numeric>
#include <vector>

class Solution {
 public:
  auto shortestDistanceAfterQueries(
      int n, std::vector<std::vector<int>>& queries) -> std::vector<int> {
    std::vector<int> res(queries.size());
    std::vector<int> next(n);
    std::iota(next.begin(), next.end(), 1);
    std::vector<bool> seen(n, false);
    int size = n - 1;
    for (size_t q = 0; q < queries.size(); ++q) {
      int s = std::min(queries[q][0], queries[q][1]);
      int e = std::max(queries[q][0], queries[q][1]);
      for (int i = next[s]; !seen[i] && i < e; i = next[i]) {
        seen[i] = true;
        --size;
      }
      next[s] = std::max(next[s], e);
      res[q] = size;
    }
    return res;
  }
};
