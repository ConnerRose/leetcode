#include <vector>

using std::vector;

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
  vector<int> rightSideView(TreeNode* root) {
    vector<int> res;
    helper(res, root, 0);
    return res;
  }

  void helper(vector<int>& res, TreeNode* node, int level) {
    if (node == nullptr) {
      return;
    }
    if (level == res.size()) {
      res.push_back(node->val);
    }
    helper(res, node->right, level + 1);
    helper(res, node->left, level + 1);
  }
};
