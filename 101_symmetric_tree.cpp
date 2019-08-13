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
  bool isSymmetric(TreeNode* root) {
    if (!root) {
      return true;
    }
    return isSymmetricHelper(root->left, root->right);
  }
  bool isSymmetricHelper(TreeNode* left, TreeNode* right) {
    if (!left && !right) {
      return true;
    }
    if (!left || !right || left->val != right->val) {
      return false;
    }
    return isSymmetricHelper(left->left, right->right) &&
           isSymmetricHelper(left->right, right->left);
  }
};

class Solution {
 public:
  bool isSymmetric(TreeNode* root) {
    if (!root) return true;
    stack<TreeNode*> nodes;
    nodes.emplace(root->left);
    nodes.emplace(root->right);
    while (!nodes.empty()) {
      auto right = nodes.top();
      nodes.pop();
      auto left = nodes.top();
      nodes.pop();
      if (!left && !right) {
        continue;
      }
      if (!left || !right || left->val != right->val) {
        return false;
      }
      nodes.push(left->left);
      nodes.push(right->right);
      nodes.push(left->right);
      nodes.push(right->left);
    }
    return true;
  }
};