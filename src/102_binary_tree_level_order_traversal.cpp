#include <queue>
#include <vector>

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  std::vector<std::vector<int>> levelOrder(TreeNode* root) {
    if (root == nullptr) {
      return {};
    }
    std::vector<std::vector<int>> res;
    std::queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      size_t level_size = q.size();
      std::vector<int> level;
      level.reserve(level_size);
      for (size_t i = 0; i < level_size; ++i) {
        TreeNode* node = q.front();
        q.pop();
        level.push_back(node->val);
        if (node->left != nullptr) {
          q.push(node->left);
        }
        if (node->right != nullptr) {
          q.push(node->right);
        }
      }
      res.push_back(level);
    }
    return res;
  }
};
