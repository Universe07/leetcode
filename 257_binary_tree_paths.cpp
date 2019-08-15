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
  vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> ans;
    vector<TreeNode*> path;
    dfs(root, path, ans);
    return ans;
  }
  void dfs(TreeNode* node, vector<TreeNode*>& path, vector<string>& ans) {
    if (!node) {
      return;
    }
    if (!node->left && !node->right) {
      string str = "";
      for (const auto& path_node : path) {
        str += to_string(path_node->val) + "->";
      }
      str += to_string(node->val);
      ans.push_back(move(str));
    }
    if (node->left) {
      path.emplace_back(node);
      dfs(node->left, path, ans);
      path.pop_back();
    }
    if (node->right) {
      path.emplace_back(node);
      dfs(node->right, path, ans);
      path.pop_back();
    }
  }
};