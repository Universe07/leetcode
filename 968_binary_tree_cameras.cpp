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
  enum class state { NONE = 0, COVERED = 1, CAMERA = 2 };
  int minCameraCover(TreeNode* root) {
    if (dfs(root) == state::NONE) ++ans;
    return ans;
  }

 private:
  int ans = 0;
  state dfs(TreeNode* root) {
    if (!root) return state::COVERED;
    state l = dfs(root->left);
    state r = dfs(root->right);
    if (l == state::NONE || r == state::NONE) {
      ++ans;
      return state::CAMERA;
    }
    if (l == state::CAMERA || r == state::CAMERA) {
      return state::COVERED;
    }
    return state::NONE;
  }
};