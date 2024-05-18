#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

class Solution {
 public:
  std::vector<double> calcEquation(
      std::vector<std::vector<std::string>>& equations,
      std::vector<double>& values,
      std::vector<std::vector<std::string>>& queries) {
    std::unordered_map<std::string, std::unordered_map<std::string, double>>
        adj;
    for (int i = 0; i < equations.size(); ++i) {
      std::string lhs = equations[i][0], rhs = equations[i][1];
      double value = values[i];
      adj[lhs][rhs] = value;
      adj[rhs][lhs] = 1 / value;
    }

    std::vector<double> res;
    res.reserve(queries.size());
    for (const std::vector<std::string>& query : queries) {
      res.push_back(answer_query(adj, query));
    }
    return res;
  }

  double answer_query(
      std::unordered_map<std::string, std::unordered_map<std::string, double>>&
          adj,
      const std::vector<std::string>& query) {
    std::string lhs = query[0], rhs = query[1];
    if (!(adj.contains(lhs) && adj.contains(rhs))) {
      return -1.0;
    }
    std::queue<std::pair<std::string, double>> q;
    std::unordered_set<std::string> seen;
    q.push({lhs, 1.0});
    seen.insert(lhs);

    while (!q.empty()) {
      auto [curr, weight] = q.front();
      q.pop();
      if (curr == rhs) {
        return weight;
      }
      for (auto [next, ratio] : adj[curr]) {
        if (seen.contains(next)) {
          continue;
        }
        q.push({next, weight * ratio});
        seen.insert(next);
      }
    }
    return -1.0;
  }
};
