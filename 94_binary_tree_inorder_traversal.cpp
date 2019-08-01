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
  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;
    TreeNode* curr = root;
    while (curr) {
      if (!curr->left) {
        ans.push_back(curr->val);
        curr = curr->right;
      } else {
        TreeNode* node = curr->left;
        while (node->right && node->right != curr) {
          node = node->right;
        }
        if (!node->right) {
          node->right = curr;
          curr = curr->left;
        } else {
          ans.push_back(curr->val);
          node->right = nullptr;
          curr = curr->right;
        }
      }
    }
    return ans;
  }
};