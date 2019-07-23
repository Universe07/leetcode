/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    stack<int> stk1, stk2;
    while (l1) {
      stk.push(l1->val);
      l1 = l1->next;
    }
    while (l2) {
      stk.push(l2->val);
      l2 = l2->next;
    }
    ListNode dummy(0);
    auto curr = &dummy;
    int carry = 0;
    while (!stk1.empty() || !stk2.empty()) {
      if (!stk1.empty()) {
        carry += stk1.top();
        stk1.pop();
      }
      if (!stk2.empty()) {
        carry += stk2.top();
        stk2.pop();
      }
      auto node = new ListNode(carry % 10);
      node->next = curr->next;
      curr->next = node;
      carry /= 10;
    }
    if (carry > 0) {
      auto node = new ListNode(carry);
      node->next = curr->next;
      curr->next = node;
    }
    return dummy.next;
  }
};