/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Time: O(n)
// Space: O(n)
class Solution {
 public:
  int rob(TreeNode* root) {
    if (root == nullptr) return 0;
    if (lookup.count(root)) return lookup[root];
    int ll = root->left ? rob(root->left->left) : 0;
    int lr = root->left ? rob(root->left->right) : 0;
    int rl = root->right ? rob(root->right->left) : 0;
    int rr = root->right ? rob(root->right->right) : 0;
    return lookup[root] = max(root->val + ll + lr + rr + rl,
                              rob(root->left) + rob(root->right));
  }

 private:
  unordered_map<TreeNode*, int> lookup;
};