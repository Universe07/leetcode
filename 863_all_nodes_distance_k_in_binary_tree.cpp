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
  vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
    buildGraph(nullptr, root);
    vector<int> ans;
    unordered_set<TreeNode*> seen;
    queue<TreeNode*> que;
    seen.insert(target);
    que.push(target);
    int k = 0;
    while (!que.empty() && k <= K) {
      int s = que.size();
      while (s--) {
        TreeNode* node = que.front();
        que.pop();
        if (k == K) ans.push_back(node->val);
        for (TreeNode* next : graph[node]) {
          if (seen.count(next)) continue;
          que.push(next);
          seen.insert(next);
        }
      }
      ++k;
    }
    return ans;
  }

 private:
  unordered_map<TreeNode*, vector<TreeNode*>> graph;
  void buildGraph(TreeNode* parent, TreeNode* child) {
    if (parent) {
      graph[parent].push_back(child);
      graph[child].push_back(parent);
    }
    if (child->left) buildGraph(child, child->left);
    if (child->right) buildGraph(child, child->right);
  }
};

// Recursion version
// Time: O(n)
// Space: O(n)

class Solution {
 public:
  vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
    ans.clear();
    dis(root, target, K);
    return ans;
  }

 private:
  vector<int> ans;
  int dis(TreeNode* root, TreeNode* target, int K) {
    if (root == nullptr) return -1;
    if (root == target) {
      collect(target, K);
      return 0;
    }
    int l = dis(root->left, target, K);
    int r = dis(root->right, target, K);
    if (l >= 0) {
      if (l == K - 1) ans.push_back(root->val);
      collect(root->right, K - l - 2);
      return l + 1;
    }
    if (r >= 0) {
      if (r == K - 1) ans.push_back(root->val);
      collect(root->left, K - r - 2);
      return r + 1;
    }
    return -1;
  }
  void collect(TreeNode* root, int d) {
    if (root == nullptr || d < 0) return;
    if (d == 0) ans.push_back(root->val);
    collect(root->left, d - 1);
    collect(root->right, d - 1);
  }
};