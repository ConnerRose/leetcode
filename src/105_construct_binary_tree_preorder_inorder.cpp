#include <algorithm>
#include <climits>
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
  TreeNode* build(vector<int>& preorder, vector<int>& inorder, int stop) {
    if (inorder.empty() || inorder.back() == stop) {
      return nullptr;
    }
    TreeNode* root = new TreeNode(preorder.back());
    preorder.pop_back();
    root->left = build(preorder, inorder, root->val);
    inorder.pop_back();
    root->right = build(preorder, inorder, stop);
    return root;
  }

 public:
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    std::reverse(preorder.begin(), preorder.end());
    std::reverse(inorder.begin(), inorder.end());
    return build(preorder, inorder, INT_MIN);
  }
};
