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
  void flatten(TreeNode* root) {
    if (!root) {
      return;
    }
    p = root;
    flatten(root->left);
    p->right = root->right;
    flatten(root->right);
    if (root->left) {
      root->right = root->left;
      root->left = nullptr;
    }
  }

 private:
  TreeNode* p;
};