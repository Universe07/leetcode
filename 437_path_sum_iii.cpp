/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// Time: O(n^2)
// Space: O(h)
class Solution {
 public:
  int pathSum(TreeNode* root, int sum) {
    if (!root) {
      return 0;
    }
    return pathSumHelper(root, 0, sum) + pathSum(root->left, sum) +
           pathSum(root->right, sum);
  }

 private:
  int pathSumHelper(TreeNode* node, int prev, int sum) {
    if (!node) {
      return 0;
    }
    auto curr = prev + node->val;
    return (curr == sum) + pathSumHelper(node->left, curr, sum) +
           pathSumHelper(node->right, curr, sum);
  }
};

// Time: O(n)
// Space: O(h)

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
  int pathSum(TreeNode* root, int sum) {
    unordered_map<int, int> lookup;
    lookup[0] = 1;
    return pathSumHelper(root, 0, sum, lookup);
  }
  int pathSumHelper(TreeNode* node, int curr, int sum,
                    unordered_map<int, int>& lookup) {
    if (!node) {
      return 0;
    }
    curr += node->val;
    int result = lookup.count(curr - sum) ? lookup[curr - sum] : 0;
    ++lookup[curr];
    result += pathSumHelper(node->left, curr, sum, lookup) +
              pathSumHelper(node->right, curr, sum, lookup);
    --lookup[curr];
    if (lookup[curr] == 0) {
      lookup.erase(curr);
    }
    return result;
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
  int pathSum(TreeNode* root, int sum) {
    ans = 0;
    lookup = {{0, 1}};
    helper(root, 0, sum);
    return ans;
  }

 private:
  int ans;
  unordered_map<int, int> lookup;
  void helper(TreeNode* node, int cur, int sum) {
    if (!node) return;
    cur += node->val;
    ans += lookup[cur - sum];
    ++lookup[cur];
    helper(node->left, cur, sum);
    helper(node->right, cur, sum);
    --lookup[cur];
  }
};