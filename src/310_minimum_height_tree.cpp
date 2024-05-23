#include <queue>
#include <vector>

class Solution {
 public:
  static auto findMinHeightTrees(int n, std::vector<std::vector<int>>& edges)
      -> std::vector<int> {
    if (n == 0) {
      return {};
    }
    if (n == 1) {
      return {0};
    }
    std::vector<int> res;
    std::vector<int> degrees(n, 0);
    std::vector<std::vector<int>> adj(n);
    for (auto& edge : edges) {
      // creating adjacent list
      adj[edge[0]].push_back(edge[1]);
      adj[edge[1]].push_back(edge[0]);
      // updating how many edges each node has
      degrees[edge[1]]++;
      degrees[edge[0]]++;
    }
    std::queue<int> queue;
    for (int i = 0; i < n; i++) {
      // adding all the leave nodes
      if (degrees[i] == 1) {
        queue.push(i);
      }
    }
    while (!queue.empty()) {
      // clear vector before we start traversing level by level.
      res.clear();
      size_t size = queue.size();
      for (size_t i = 0; i < size; i++) {
        int cur = queue.front();
        queue.pop();
        // adding nodes to vector.
        // Goal is to get a vector of  just 1 or 2 nodes available.
        res.push_back(cur);
        for (auto& neighbor : adj[cur]) {
          // removing current leave nodes
          degrees[neighbor]--;
          if (degrees[neighbor] == 1) {
            // adding current leave nodes
            queue.push(neighbor);
          }
        }
      }
    }
    return res;
  }
};
