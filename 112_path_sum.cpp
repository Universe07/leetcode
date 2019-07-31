/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Time : O(n)
// Space : O(n)
class Solution {
 public:
  bool hasPathSum(TreeNode* root, int sum) {
    if (!root) {
      return false;
    }
    int temp = root->val;
    if (!root->left && !root->right) {
      return sum == temp;
    } else {
      return hasPathSum(root->left, sum - temp) ||
             hasPathSum(root->right, sum - temp);
    }
  }
};