#include <unordered_map>
#include <vector>

class Node {
 public:
  int val;
  std::vector<Node*> neighbors;
  Node() {
    val = 0;
    neighbors = std::vector<Node*>();
  }
  Node(int _val) {
    val = _val;
    neighbors = std::vector<Node*>();
  }
  Node(int _val, std::vector<Node*> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

class Solution {
 public:
  Node* dfs(Node* cur, std::unordered_map<Node*, Node*>& mp) {
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
    std::unordered_map<Node*, Node*> map;
    return dfs(node, map);
  }
};
