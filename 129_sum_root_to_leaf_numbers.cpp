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
  int sumNumbers(TreeNode* root) { return dfs(root, 0); }
  int dfs(TreeNode* node, int num) {
    if (!node) {
      return 0;
    }
    num = num * 10 + node->val;
    if (!node->left && !node->right) {
      return num;
    }
    return dfs(node->left, num) + dfs(node->right, num);
  }
};