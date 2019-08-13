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
  int minDepth(TreeNode* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 1;
    int l = minDepth(root->left);
    int r = minDepth(root->right);
    if (!root->left) return r + 1;
    if (!root->right) return l + 1;
    return min(l, r) + 1;
  }
};

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
  int minDepth(TreeNode* root) {
    if (!root) return 0;
    int level = 0;
    queue<TreeNode*> que;
    que.push(root);
    while (!que.empty()) {
      level++;
      int size = que.size();
      for (int i = 0; i < size; ++i) {
        auto node = que.front();
        que.pop();
        if (node->left) que.push(node->left);
        if (node->right) que.push(node->right);
        if (!node->left && !node->right) {
          return level;
        }
      }
    }
    return -1;
  }
};