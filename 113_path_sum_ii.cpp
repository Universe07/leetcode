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
  vector<vector<int>> pathSum(TreeNode* root, int sum) {
    pathSumImple(root, sum);
    return ans;
  }

 private:
  vector<int> v;
  vector<vector<int>> ans;
  void pathSumImple(TreeNode* node, int sum) {
    if (!node) {
      return;
    }
    v.push_back(node->val);
    if (!node->left && !node->right && node->val == sum) {
      ans.push_back(v);
    }
    pathSumImple(node->left, sum - node->val);
    pathSumImple(node->right, sum - node->val);
    v.pop_back();
  }
};