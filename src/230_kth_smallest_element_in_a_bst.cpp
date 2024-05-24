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
  int k = 0;
  int count = 0;
  int res = 0;

  auto helper(TreeNode* node) -> void {
    if (node->left != nullptr) {
      helper(node->left);
    }
    ++count;
    if (count == k) {
      res = node->val;
      return;
    }
    if (node->right != nullptr) {
      helper(node->right);
    }
  }

 public:
  auto kthSmallest(TreeNode* root, int k) -> int {
    this->k = k;
    helper(root);
    return res;
  }
};
