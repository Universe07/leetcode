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
// Space: O(n)
class Solution {
 public:
  vector<int> findMode(TreeNode* root) {
    inorder(root);
    return ans;
  }

 private:
  vector<int> ans;
  int count = 0;
  int val = 0;
  int max_count = 0;
  void inorder(TreeNode* node) {
    if (!node) return;
    inorder(node->left);
    visit(node->val);
    inorder(node->right);
  }
  void visit(int visitedVal) {
    if (count > 0 && val == visitedVal) {
      count++;
    } else {
      count = 1;
      val = visitedVal;
    }
    if (count > max_count) {
      max_count = count;
      ans.clear();
    }
    if (count == max_count) {
      ans.push_back(visitedVal);
    }
  }
};

// Time: O(n)
// Space: O(1)

class Solution {
 public:
  vector<int> findMode(TreeNode* root) {
    inorder(root);
    mode_count = max_count;
    count = 0;
    inorder(root);
    return ans;
  }

 private:
  int val = 0;
  int max_count = 0;
  int count = 0;
  int mode_count = INT_MAX;
  vector<int> ans;

  void inorder(TreeNode* node) {
    if (node == nullptr) return;
    inorder(node->left);
    visited(node->val);
    inorder(node->right);
  }
  void visited(int visitVal) {
    if (count > 0 && visitVal == val) {
      ++count;
    } else {
      val = visitVal;
      count = 1;
    }
    if (count > max_count) {
      max_count = count;
    }
    if (count == mode_count) {
      ans.push_back(visitVal);
    }
  }
};