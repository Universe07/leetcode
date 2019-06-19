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
    unordered_map<Node *, int> node_map;
    vector<Node *> node_vec;
    Node *ptr = head;
    int i = 0;
    while (ptr) {
      node_vec.push_back(new Node(ptr->val));
      node_map[ptr] = i;
      ptr = ptr->next;
      i++;
    }
    node_vec.push_back(0);
    ptr = head;
    i = 0;
    while (ptr) {
      node_vec[i]->next = node_vec[i + 1];
      if (ptr->random) {
        node_vec[i]->random = node_vec[node_map[ptr->random]];
      }
      ptr = ptr->next;
      i++;
    }
    return node_vec[0];
  }
};