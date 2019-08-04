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
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    return helper(nums, 0, nums.size() - 1);
  }
  TreeNode* helper(vector<int>& nums, int start, int end) {
    if (start <= end) {
      TreeNode* node = new TreeNode(nums[start + (end - start) / 2]);
      node->left = helper(nums, start, start + (end - start) / 2 - 1);
      node->right = helper(nums, start + (end - start) / 2 + 1, end);
      return node;
    }
    return nullptr;
  }
};