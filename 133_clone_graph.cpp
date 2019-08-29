/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
 public:
  Node* cloneGraph(Node* node) {
    if (!node) return nullptr;
    unordered_set<Node*> done;
    unordered_map<Node*, Node*> m;
    queue<Node*> que;
    que.push(node);
    while (!que.empty()) {
      Node* node = que.front();
      que.pop();
      if (done.count(node)) continue;
      done.insert(node);
      if (!m.count(node)) m[node] = new Node(node->val);
      Node* temp = m[node];
      for (Node* ss : node->neighbors) {
        if (!m.count(ss)) m[ss] = new Node(ss->val);
        que.push(ss);
        temp->neighbors.push_back(m[ss]);
      }
    }
    return m[node];
  }
};