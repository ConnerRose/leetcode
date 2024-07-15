#include <algorithm>
#include <climits>
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
  int res = INT_MIN;

  auto helper(TreeNode* root) {
    if (root == nullptr) {
      return 0;
    }
    int l = std::max(helper(root->left), 0);
    int r = std::max(helper(root->right), 0);
    res = std::max(res, root->val + l + r);
    return root->val + std::max(l, r);
  }

 public:
  auto maxPathSum(TreeNode* root) -> int {
    helper(root);
    return res;
  }
};
