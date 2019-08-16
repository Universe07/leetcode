/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
 public:
  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    string data = "";
    serialize(root, &data);
    return data;
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    int pos = 0;
    int maxVal = INT_MAX;
    int minVal = INT_MIN;
    return deserialize(&pos, data, minVal, maxVal);
  }

 private:
  void serialize(TreeNode* node, string* data) {
    if (!node) {
      return;
    }
    *data += to_string(node->val) + ' ';
    serialize(node->left, data);
    serialize(node->right, data);
  }
  TreeNode* deserialize(int* pos, string& data, int minVal, int maxVal) {
    if (*pos == data.size()) {
      return nullptr;
    }
    int end = data.find(' ', *pos);
    auto val = stoi(data.substr(*pos, end - *pos));
    if (val < maxVal && val > minVal) {
      TreeNode* node = new TreeNode(val);
      *pos = end + 1;
      node->left = deserialize(pos, data, minVal, val);
      node->right = deserialize(pos, data, val, maxVal);
      return node;
    } else {
      return nullptr;
    }
  }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));