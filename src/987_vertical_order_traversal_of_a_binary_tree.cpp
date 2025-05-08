#include <algorithm>
#include <map>
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
  std::map<int, std::vector<std::pair<int, int>>> m;
  auto helper(TreeNode* root, int col, int depth) -> void {
    if (root == nullptr) {
      return;
    }
    m[col].emplace_back(depth, root->val);
    helper(root->left, col - 1, depth + 1);
    helper(root->right, col + 1, depth + 1);
  }

 public:
  auto verticalTraversal(TreeNode* root) -> std::vector<std::vector<int>> {
    helper(root, 0, 0);
    std::vector<std::vector<int>> ans;
    ans.reserve(m.size());
    for (auto& [col, values] : m) {
      std::sort(values.begin(), values.end());
      ans.emplace_back();
      for (auto p : values) {
        ans.back().emplace_back(p.second);
      }
    }
    return ans;
  }
};
