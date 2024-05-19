#include <sstream>
#include <string>

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec {
  void serialize(TreeNode* root, std::ostringstream& out) {
    if (root) {
      out << root->val << ' ';
      serialize(root->left, out);
      serialize(root->right, out);
    } else {
      out << "# ";
    }
  }

  TreeNode* deserialize(std::istringstream& in) {
    std::string val;
    in >> val;
    if (val == "#") {
      return nullptr;
    }
    TreeNode* node = new TreeNode(std::stoi(val));
    node->left = deserialize(in);
    node->right = deserialize(in);
    return node;
  }

 public:
  std::string serialize(TreeNode* root) {
    std::ostringstream out;
    serialize(root, out);
    return out.str();
  }

  TreeNode* deserialize(std::string data) {
    std::istringstream in(data);
    return deserialize(in);
  }
};
