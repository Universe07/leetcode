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
  int kthSmallest(TreeNode* root, int k) {
    stack<TreeNode*> stk;
    TreeNode* curr = root;
    int rank = 0;
    while (!stk.empty() || curr) {
      if (curr) {
        stk.push(curr);
        curr = curr->left;
      } else {
        curr = stk.top();
        stk.pop();
        if (++rank == k) {
          return curr->val;
        }
        curr = curr->right;
      }
    }
    return INT_MIN;
  }
};