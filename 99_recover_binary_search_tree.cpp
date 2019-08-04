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
  void recoverTree(TreeNode* root) {
    if (!root) {
      return;
    }
    pair<TreeNode*, TreeNode*> bad;
    TreeNode* prev = nullptr;
    TreeNode* curr = root;
    while (curr) {
      if (!curr->left) {
        detect(prev, curr, bad);
        prev = curr;
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
          detect(prev, curr, bad);
          prev = curr;
          node->right = nullptr;
          curr = curr->right;
        }
      }
    }
    swap(bad.first->val, bad.second->val);
  }

 private:
  void detect(TreeNode* prev, TreeNode* node, pair<TreeNode*, TreeNode*>& bad) {
    if (prev && prev->val > node->val) {
      if (!bad.first) {
        bad.first = prev;
      }
      bad.second = node;
    }
  }
};