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
  vector<int> findFrequentTreeSum(TreeNode* root) {
    if (!root) return {};
    unordered_map<int, int> lookup;
    int max_count = 0;
    countHelper(root, &lookup, &max_count);
    vector<int> ans;
    for (const auto& pair : lookup) {
      if (pair.second == max_count) {
        ans.push_back(pair.first);
      }
    }
    return ans;
  }

 private:
  int countHelper(TreeNode* node, unordered_map<int, int>* lookup,
                  int* max_count) {
    if (!node) {
      return 0;
    }
    auto sum = node->val + countHelper(node->left, lookup, max_count) +
               countHelper(node->right, lookup, max_count);
    ++(*lookup)[sum];
    *max_count = max((*lookup)[sum], *max_count);
    return sum;
  }
};