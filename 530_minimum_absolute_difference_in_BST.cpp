/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Space: O(n)
// Time: O(n)
class Solution {
 public:
  int getMinimumDifference(TreeNode* root) {
    vector<int> sorted;
    inorder(root, sorted);
    int min_diff = sorted.bach();
    for (int i = 0; i < sorted.size() - 1; ++i) {
      min_diff = min(sorted[i + 1] - sorted[i], min_diff);
    }
    return min_diff;
  }
  void inorder(TreeNode* root, vector<int>& sorted) {
    if (!root) return;
    inorder(root->left, sorted);
    sorted.push_back(root->val);
    inorder(root->right, sorted);
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
  int getMinimumDifference(TreeNode* root) {
    min_diff = INT_MAX;
    prev = nullptr;
    inorder(root);
    return min_diff;
  }
  void inorder(TreeNode* node) {
    if (!node) return;
    inorder(node->left);
    if (prev) min_diff = min(node->val - *prev, min_diff);
    prev = &node->val;
    inorder(node->right);
  }

 private:
  int min_diff;
  int* prev;
};