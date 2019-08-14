/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
 public:
  vector<vector<int>> levelOrder(Node* root) {
    if (!root) return {};
    vector<vector<int>> ans;
    queue<Node*> que;
    que.push(root);
    int size = que.size();
    vector<int> temp;
    while (size--) {
      auto node = que.front();
      que.pop();
      temp.push_back(node->val);
      for (const auto& child : node->children) {
        if (child) {
          que.push(child);
        }
      }
      if (size == 0) {
        ans.push_back(move(temp));
        size = que.size();
      }
    }
    return ans;
  }
};