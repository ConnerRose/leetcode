#include <map>
#include <set>
#include <unordered_map>
#include <utility>
#include <vector>

class Solution {
  std::unordered_map<int, std::vector<int>> adj;
  std::map<std::pair<int, int>, int> dp;
  std::set<std::pair<int, int>> guess_set;

  auto dfs(int parent, int node) {
    if (dp.contains(std::make_pair(parent, node))) {
      return dp[std::make_pair(parent, node)];
    }
    int correct = guess_set.contains(std::make_pair(parent, node)) ? 1 : 0;
    for (int neighbor : adj[node]) {
      if (neighbor != parent) {
        correct += dfs(node, neighbor);
      }
    }
    return dp[std::make_pair(parent, node)] = correct;
  }

 public:
  auto rootCount(const std::vector<std::vector<int>>& edges,
                 const std::vector<std::vector<int>>& guesses, int k) -> int {
    for (const auto& pair : edges) {
      adj[pair[0]].push_back(pair[1]);
      adj[pair[1]].push_back(pair[0]);
    }
    for (const auto& pair : guesses) {
      guess_set.insert(std::make_pair(pair[0], pair[1]));
    }
    int res = 0;
    for (auto& [node, _] : adj) {
      if (dfs(-1, node) >= k) {
        ++res;
      }
    }
    return res;
  }
};
