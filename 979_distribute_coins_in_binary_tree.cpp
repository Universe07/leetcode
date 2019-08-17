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
  int distributeCoins(TreeNode* root) {
    int ans = 0;
    balance(root, ans);
    return ans;
  }
  int balance(TreeNode* node, int& ans) {
    if (!node) return 0;
    int left = balance(node->left, ans);
    int right = balance(node->right, ans);
    ans += abs(left) + abs(right);
    return left + right + node->val - 1;
  }
};