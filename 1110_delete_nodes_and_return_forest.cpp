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
// Space: O(H + n)

class Solution {
 public:
  vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
    vector<TreeNode*> res;
    set<int> to_delete_set;
    for (int i : to_delete) to_delete_set.insert(i);
    helper(root, res, to_delete_set, true);
    return res;
  }

 private:
  TreeNode* helper(TreeNode* node, vector<TreeNode*>& res,
                   set<int>& to_delete_set, bool is_root) {
    if (!node) return nullptr;
    bool deleted = to_delete_set.find(node->val) != to_delete_set.end();
    if (is_root && !deleted) res.push_back(node);
    node->left = helper(node->left, res, to_delete_set, deleted);
    node->right = helper(node->right, res, to_delete_set, deleted);
    return deleted ? nullptr : node;
  }
};