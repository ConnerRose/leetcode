#include <vector>

using std::vector;

class Solution {
 public:
  bool canFinish(int num_courses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adj(num_courses);
    vector<int> deg(num_courses, 0);
    vector<int> bfs;
    // Create adjacency list and initialize node indegrees
    for (const vector<int>& pair : prerequisites) {
      adj[pair[1]].push_back(pair[0]);
      ++deg[pair[0]];
    }
    // Initialize bfs with roots
    for (int i = 0; i < num_courses; ++i) {
      if (deg[i] == 0) {
        bfs.push_back(i);
      }
    }

    for (int i = 0; i < bfs.size(); ++i) {
      for (int j : adj[bfs[i]]) {
        --deg[j];
        if (deg[j] == 0) {
          bfs.push_back(j);
        }
      }
    }
    return bfs.size() == num_courses;
  }
};
