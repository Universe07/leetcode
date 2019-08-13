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
  vector<int> preorder(Node* root) {
    if (!root) return {};
    vector<int> ans;
    vector<Node*> nodes{root};
    while (!nodes.empty()) {
      auto node = nodes.back();
      nodes.pop_back();
      if (!node) continue;
      ans.emplace_back(node->val);
      for (auto rit = node->children.rbegin(); rit != node->children.rend();
           ++rit) {
        if (*rit) {
          nodes.push_back(*rit);
        }
      }
    }
    return ans;
  }
};