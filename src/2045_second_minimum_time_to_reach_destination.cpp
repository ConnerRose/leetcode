#include <algorithm>
#include <queue>
#include <utility>
#include <vector>

class Solution {
 public:
  static auto secondMinimum(int n, std::vector<std::vector<int>>& edges,
                            int time, int change) -> int {
    std::vector<std::vector<int>> adj(n + 1);
    for (const auto& edge : edges) {
      adj[edge[0]].push_back(edge[1]);
      adj[edge[1]].push_back(edge[0]);
    }
    std::vector<std::vector<int>> distances(n + 1);
    using p = std::pair<int, int>;
    std::priority_queue<p, std::vector<p>, std::greater<>> pq;
    distances[1].push_back(0);
    pq.emplace(0, 1);
    while (!pq.empty()) {
      auto [t, idx] = pq.top();
      pq.pop();
      if (idx == n && distances[n].size() == 2) {
        return std::max(distances[n][0], distances[n][1]);
      }
      for (int neighbor : adj[idx]) {
        int new_t = (t / change) % 2 == 0
                        ? t + time
                        : (t / (2 * change) + 1) * 2 * change + time;
        if (distances[neighbor].empty() || (distances[neighbor].size() == 1 &&
                                            distances[neighbor][0] != new_t)) {
          distances[neighbor].push_back(new_t);
          pq.emplace(new_t, neighbor);
        }
      }
    }
    return -1;
  }
};
