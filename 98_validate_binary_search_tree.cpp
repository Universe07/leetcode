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
  bool isValidBST(TreeNode* root) {
    TreeNode* prev = nullptr;
    return validate(root, prev);
  }
  bool validate(TreeNode* node, TreeNode*& prev) {
    if (node == nullptr) return true;
    if (!validate(node->left, prev)) return false;
    if (prev != nullptr && node->val <= prev->val) return false;
    prev = node;
    return validate(node->right, prev);
  }
};