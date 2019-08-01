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
  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;
    TreeNode* curr = root;
    while (curr) {
      if (!curr->left) {
        ans.push_back(curr->val);
        curr = curr->right;
      } else {
        TreeNode* node = curr->left;
        while (node->right && node->right != curr) {
          node = node->right;
        }
        if (!node->right) {
          node->right = curr;
          curr = curr->left;
        } else {
          ans.push_back(curr->val);
          node->right = nullptr;
          curr = curr->right;
        }
      }
    }
    return ans;
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
  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;
    stack<pair<TreeNode*, bool>> stk;
    stk.push(make_pair(root, false));
    while (!stk.empty()) {
      bool visited;
      TreeNode* node;
      tie(node, visited) = stk.top();
      stk.pop();
      if (!node) {
        continue;
      }
      if (visited) {
        ans.emplace_back(node->val);
      } else {
        stk.push(make_pair(node->right, false));
        stk.push(make_pair(node, true));
        stk.push(make_pair(node->left, false));
      }
    }
    return ans;
  }
};