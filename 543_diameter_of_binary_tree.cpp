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
  int diameterOfBinaryTree(TreeNode* root) {
    max_length = 0;
    dfs(root);
    return max_length;
  }

 private:
  int max_length;
  int dfs(TreeNode* node) {
    if (!node) {
      return 0;
    }
    int l = dfs(node->left);
    int r = dfs(node->right);
    max_length = max(max_length, l + r);
    return l > r ? l + 1 : r + 1;
  }
};