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
  bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    if (!root1 && !root2) {
      return true;
    }
    stack<TreeNode*> stk1, stk2;
    stk1.push(root1);
    stk2.push(root2);
    while (!stk1.empty() && !stk2.empty()) {
      if (dfs(stk1) != dfs(stk2)) {
        return false;
      }
    }
    return stk1.empty() && stk2.empty();
  }
  int dfs(stack<TreeNode*>& stk) {
    while (true) {
      auto node = stk.top();
      stk.pop();
      if (node->left) {
        stk.push(node->left);
      }
      if (node->right) {
        stk.push(node->right);
      }
      if (!node->left && !node->right) {
        return node->val;
      }
    }
  }
};