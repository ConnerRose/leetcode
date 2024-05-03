#include <unordered_map>
#include <vector>

using std::unordered_map;
using std::vector;

class Node {
 public:
  int val;
  vector<Node*> neighbors;
  Node() {
    val = 0;
    neighbors = vector<Node*>();
  }
  Node(int _val) {
    val = _val;
    neighbors = vector<Node*>();
  }
  Node(int _val, vector<Node*> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

class Solution {
 public:
  Node* dfs(Node* cur, unordered_map<Node*, Node*>& mp) {
    Node* clone = new Node(cur->val);
    mp[cur] = clone;
    for (Node* neighbor : cur->neighbors) {
      if (mp.contains(neighbor)) {
        clone->neighbors.push_back(mp[neighbor]);
      } else {
        clone->neighbors.push_back(dfs(neighbor, mp));
      }
    }
    return clone;
  }

  Node* cloneGraph(Node* node) {
    if (node == nullptr) {
      return nullptr;
    }
    if (node->neighbors.size() == 0) {
      return new Node(node->val);
    }
    unordered_map<Node*, Node*> map;
    return dfs(node, map);
  }
};
