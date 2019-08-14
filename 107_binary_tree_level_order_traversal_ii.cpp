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
  vector<vector<int>> levelOrderBottom(TreeNode* root) {
    if (!root) return {};
    vector<vector<int>> ans;
    queue<TreeNode*> que;
    vector<int> temp;
    que.push(root);
    int size = que.size();
    while (size--) {
      auto node = que.front();
      que.pop();
      temp.push_back(node->val);
      if (node->left) que.push(node->left);
      if (node->right) que.push(node->right);
      if (size == 0) {
        ans.push_back(move(temp));
        size = que.size();
      }
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};