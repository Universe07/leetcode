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
  vector<int> rightSideView(TreeNode* root) {
    vector<int> ans;
    if (!root) {
      return ans;
    }
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      auto size = q.size();
      while (size--) {
        auto tmp = q.front();
        q.pop();
        if (size == 0) ans.push_back(tmp->val);
        if (tmp->left) q.push(tmp->left);
        if (tmp->right) q.push(tmp->right);
      }
    }
    return ans;
  }
};