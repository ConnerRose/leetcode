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
  bool isValidBST(TreeNode* root, TreeNode* min_node = nullptr,
                  TreeNode* max_node = nullptr) {
    if (root == nullptr) {
      return true;
    }
    if (min_node && root->val <= min_node->val ||
        max_node && root->val >= max_node->val) {
      return false;
    }
    return isValidBST(root->left, min_node, root) &&
           isValidBST(root->right, root, max_node);
  }
};
