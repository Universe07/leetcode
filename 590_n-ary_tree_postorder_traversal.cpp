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
  vector<int> postorder(Node* root) {
    if (!root) return {};
    vector<int> ans;
    vector<Node*> nodes{root};
    while (!nodes.empty()) {
      auto node = nodes.back();
      nodes.pop_back();
      ans.emplace_back(node->val);
      for (const auto& child : node->children) {
        if (child) {
          nodes.push_back(child);
        }
      }
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};