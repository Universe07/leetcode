/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// Time: O(n)

class Codec {
 public:
  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    ostringstream output;
    serializeHelper(root, output);
    return output.str();
  }
  void serializeHelper(TreeNode* node, ostringstream& output) {
    if (!node) {
      output << "# ";
      return;
    }
    output << node->val << " ";
    serializeHelper(node->left, output);
    serializeHelper(node->right, output);
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    istringstream in(data);
    return deserializeHelper(in);
  }
  TreeNode* deserializeHelper(istringstream& in) {
    string val;
    in >> val;
    if (val == "#") {
      return nullptr;
    } else {
      TreeNode* root = new TreeNode(stoi(val));
      root->left = deserializeHelper(in);
      root->right = deserializeHelper(in);
      return root;
    }
  }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));