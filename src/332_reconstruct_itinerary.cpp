#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
 public:
  auto findItinerary(std::vector<std::vector<std::string>>& tickets)
      -> std::vector<std::string> {
    std::unordered_map<std::string, std::vector<std::string>> adj;
    for (const auto& ticket : tickets) {
      adj[ticket[0]].push_back(ticket[1]);
    }
    for (auto& [_, neighbors] : adj) {
      std::sort(neighbors.begin(), neighbors.end(), std::greater<>());
    }
    std::vector<std::string> res;
    res.reserve(tickets.size() + 1);
    std::vector<std::string> st = {"JFK"};
    while (!st.empty()) {
      while (!adj[st.back()].empty()) {
        auto& vec = adj[st.back()];
        st.push_back(vec.back());
        vec.pop_back();
      }
      res.push_back(st.back());
      st.pop_back();
    }
    std::reverse(res.begin(), res.end());
    return res;
  }
};
