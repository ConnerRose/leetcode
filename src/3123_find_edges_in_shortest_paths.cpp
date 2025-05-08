#include <limits>
#include <queue>
#include <vector>

class Solution {
 public:
  std::vector<bool> findAnswer(int n, std::vector<std::vector<int>>& edges) {
    std::vector<int> dist(n, std::numeric_limits<int>::max());
    std::vector<std::vector<std::pair<int, int>>> adj(n);
    for (int i = 0; i < edges.size(); ++i) {
      adj[edges[i][0]].emplace_back(edges[i][1], i);
      adj[edges[i][1]].emplace_back(edges[i][0], i);
    }
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                        std::greater<>>
        pq;
    pq.emplace(0, 0);
    dist[0] = 0;
    while (!pq.empty()) {
      auto [d, u] = pq.top();
      pq.pop();
      if (d == dist[u]) {
        for (const auto [v, e] : adj[u]) {
          if (d + edges[e][2] < dist[v]) {
            pq.emplace(dist[v] = d + edges[e][2], v);
          }
        }
      }
    }
    std::vector<bool> res(edges.size());
    std::vector<bool> visited(n);
    std::vector<std::pair<int, int>> st;
    st.emplace_back(dist[n - 1], n - 1);
    while (!st.empty()) {
      auto [d, u] = st.back();
      st.pop_back();
      for (const auto [v, e] : adj[u]) {
        if (d - edges[e][2] == dist[v]) {
          if (!visited[v]) {
            st.emplace_back(dist[v], v);
          }
          res[e] = visited[v] = true;
        }
      }
    }
    return res;
  }
};
