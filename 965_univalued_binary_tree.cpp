/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
 public:
  bool isUnivalTree(TreeNode* root) {
    int val = root->val;
    return equal(root, val);
  }

 private:
  bool equal(TreeNode* node, int val) {
    if (!node) {
      return true;
    }
    bool left = equal(node->left, val);
    bool right = equal(node->right, val);
    return node->val == val && left && right;
  }
};