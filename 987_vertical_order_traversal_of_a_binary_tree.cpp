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
  vector<vector<int>> verticalTraversal(TreeNode* root) {
    if (!root) return {};
    vector<vector<int>> ans;
    map<int, vector<pair<int, int>>> dict;
    queue<pair<TreeNode*, pair<int, int>>> que;
    que.push({root, {0, 0}});
    int height, depth;
    while (!que.empty()) {
      auto front = que.front();
      que.pop();
      auto node = front.first;
      auto location = front.second;
      height = location.first;
      depth = location.second;
      dict[height].push_back(make_pair(depth, node->val));
      if (node->left) {
        que.push(make_pair(node->left, make_pair(height - 1, depth + 1)));
      }
      if (node->right) {
        que.push(make_pair(node->right, make_pair(height + 1, depth + 1)));
      }
    }
    ans.resize(dict.size());
    int index = 0;
    for (const auto& line : dict) {
      auto pairs = line.second;
      sort(pairs.begin(), pairs.end());
      for (const auto& pair : pairs) {
        ans[index].push_back(pair.second);
      }
      index++;
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

class Node {
 public:
  TreeNode* node;
  int x;
  int y;
  Node(TreeNode* node, int x, int y) : node(node), x(x), y(y) {}
};

class Solution {
 public:
  vector<vector<int>> verticalTraversal(TreeNode* root) {
    if (!root) return {};
    stack<Node*> stk;
    vector<Node*> store;
    stk.push(new Node(root, 0, 0));
    while (!stk.empty()) {
      auto tmp = stk.top();
      stk.pop();
      store.push_back(tmp);
      int x = tmp->x;
      int y = tmp->y;
      auto treenode = tmp->node;
      if (treenode->left) {
        stk.push(new Node(treenode->left, x - 1, y + 1));
      }
      if (treenode->right) {
        stk.push(new Node(treenode->right, x + 1, y + 1));
      }
    }
    auto cmp = [](const Node* node1, const Node* node2) {
      if (node1->x == node2->x) {
        if (node1->y == node2->y) {
          return node1->node->val < node2->node->val;
        }
        return node1->y < node2->y;
      }
      return node1->x < node2->x;
    };
    sort(store.begin(), store.end(), cmp);
    vector<int> temp;
    vector<vector<int>> ans;
    int i = 0;
    for (; i < store.size() - 1; ++i) {
      if (store[i]->x == store[i + 1]->x) {
        temp.push_back(store[i]->node->val);
      } else {
        temp.push_back(store[i]->node->val);
        ans.push_back(move(temp));
      }
    }
    temp.push_back(store[i]->node->val);
    ans.push_back(move(temp));
    return ans;
  }
};