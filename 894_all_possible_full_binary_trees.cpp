/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
 public:
  vector<TreeNode*> allPossibleFBT(int N) {
    vector<TreeNode*> res;
    if (N == 1)
      res.emplace_back(new TreeNode(0));
    else if (N % 2) {
      for (int i = 2; i <= N; i += 2) {
        auto left = allPossibleFBT(i - 1);
        auto right = allPossibleFBT(N - i);
        for (int l_idx = 0; l_idx < left.size(); ++l_idx) {
          for (int r_idx = 0; r_idx < right.size(); ++r_idx) {
            res.emplace_back(new TreeNode(0));
            res.back()->left =
                (r_idx == right.size() - 1) ? left[l_idx] : clone(left[l_idx]);
            res.back()->right =
                (l_idx == left.size() - 1) ? right[r_idx] : clone(right[r_idx]);
          }
        }
      }
    }
    return res;
  }
  TreeNode* clone(TreeNode* node) {
    TreeNode* next = new TreeNode(0);
    next->left = (node->left) ? clone(node->left) : nullptr;
    next->right = (node->right) ? clone(node->right) : nullptr;
    return next;
  }
};