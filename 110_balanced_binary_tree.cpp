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
  bool isBalanced(TreeNode* root) {
    if (!root) return true;
    bool balance = true;
    height(root, &balance);
    return balance;
  }
  int height(TreeNode* node, bool* balance) {
    if (!node) return 0;
    int leftHeight = height(node->left, balance);
    if (!balance) return -1;
    int rightHeight = height(node->right, balance);
    if (!balance) return -1;
    if (abs(leftHeight - rightHeight) > 1) {
      *balance = false;
      return -1;
    }
    return max(leftHeight, rightHeight) + 1;
  }
};