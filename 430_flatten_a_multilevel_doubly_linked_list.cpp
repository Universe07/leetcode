/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
 public:
  Node* flatten(Node* head) {
		if (head == nullptr) return nullptr;
		stack<Node*> stk;
		stk.push(head);
		Node* curr = nullptr, *prev = nullptr, *newhead = nullptr;
		while (!stk.empty()) {
			prev = curr;
			curr = stk.top(), stk.pop();
			if (curr -> next) stk.push(curr -> next);
			if (curr -> child) stk.push(curr -> child);
			curr -> child = nullptr;
			curr -> prev = prev;
			if (prev) prev -> next = curr;
			else newhead = curr;
		}
		return newhead;
	}
};