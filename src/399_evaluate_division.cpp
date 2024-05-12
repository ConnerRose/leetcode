#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using std::pair;
using std::queue;
using std::string;
using std::unordered_map;
using std::unordered_set;
using std::vector;

class Solution {
 public:
  vector<double> calcEquation(vector<vector<string>>& equations,
                              vector<double>& values,
                              vector<vector<string>>& queries) {
    unordered_map<string, unordered_map<string, double>> adj;
    for (int i = 0; i < equations.size(); ++i) {
      string lhs = equations[i][0], rhs = equations[i][1];
      double value = values[i];
      adj[lhs][rhs] = value;
      adj[rhs][lhs] = 1 / value;
    }

    vector<double> res;
    res.reserve(queries.size());
    for (const vector<string>& query : queries) {
      res.push_back(answer_query(adj, query));
    }
    return res;
  }

  double answer_query(unordered_map<string, unordered_map<string, double>>& adj,
                      const vector<string>& query) {
    string lhs = query[0], rhs = query[1];
    if (!(adj.contains(lhs) && adj.contains(rhs))) {
      return -1.0;
    }
    queue<pair<string, double>> q;
    unordered_set<string> seen;
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
