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
  int maxPathSum(TreeNode* root) {
    max_sum = INT_MIN;
    dfs(root);
    return max_sum;
  }

 private:
  int max_sum;
  int dfs(TreeNode* node) {
    if (!node) {
      return 0;
    }
    int l = dfs(node->left);
    int r = dfs(node->right);
    int sum = node->val;
    if (l > 0) sum += l;
    if (r > 0) sum += r;
    max_sum = max(max_sum, sum);
    return max(l, r) > 0 ? max(r, l) + node->val : node->val;
  }
};