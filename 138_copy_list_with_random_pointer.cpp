/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
// Time: O(n)
// Space: O(n)

class Solution {
 public:
  Node *copyRandomList(Node *head) {
    if (head == nullptr) {
      return nullptr;
    }
    for (Node *curr = head; curr; curr = curr->next->next) {
      Node *node = new Node(curr->val, curr->next, nullptr);
      curr->next = node;
    }
    for (Node *curr = head; curr; curr = curr->next->next) {
      curr->next->random = curr->random->next;
    }
    Node dummy(0);
    for (Node *curr = head, Node *copy_curr = &dummy; curr;
         curr = curr->next, copy_curr = copy_curr->next) {
      copy_curr->next = curr->next;
      curr->next = curr->next->next;
    }
    return dummy.next;
  }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
// Time: O(n)
// Space: O(n)
class Solution {
 public:
  Node *copyRandomList(Node *head) {
    unordered_map<Node *, Node *> node_map;
    return helper(head, node_map);
  }
  Node *helper(Node *node, unordered_map<Node *, Node *> &node_map) {
    if (!node) return nullptr;
    if (node_map.count(node)) return node_map[node];
    Node *res = new Node(node->val, nullptr, nullptr);
    node_map[node] = res;
    res->next = helper(node->next, node_map);
    res->random = helper(node->random, ndoe);
    return res;
  }
};