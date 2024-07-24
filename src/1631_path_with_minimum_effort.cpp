#include <climits>
#include <cstdlib>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

class Solution {
 public:
  static int minimumEffortPath(vector<vector<int>>& heights) {
    int n = static_cast<int>(heights.size());
    int m = static_cast<int>(heights[0].size());
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    vector<int> dirs = {0, 1, 0, -1, 0};

    using tup = tuple<int, int, int>;
    priority_queue<tup, vector<tup>, greater<>> pq;

    pq.emplace(0, 0, 0);

    while (!pq.empty()) {
      auto [d, r, c] = pq.top();
      pq.pop();
      if (d > dist[r][c]) {
        continue;
      }
      if (r == n - 1 && c == m - 1) {
        return d;
      }
      for (int k = 0; k < 4; ++k) {
        int x = r + dirs[k];
        int y = c + dirs[k + 1];
        if (x < 0 || x >= n || y < 0 || y >= m) {
          continue;
        }
        int new_dist =
            min(dist[x][y], max(d, abs(heights[x][y] - heights[r][c])));
        if (new_dist < dist[x][y]) {
          dist[x][y] = new_dist;
          pq.emplace(dist[x][y], x, y);
        }
      }
    }
    return 0;
  }
};
