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
    ListNode dummy(0);
    auto curr = &dummy;
    int carry = 0;
    while (l1 || l2 || carry) {
      int a = l1 ? l1->val : 0, b = l2 ? l2->val : 0;
      int sum = carry + a + b;
      curr->next = new ListNode(sum % 10);
      curr = curr->next;
      l1 = l1 ? l1->next : nullptr;
      l2 = l2 ? l2->next : nullptr;
      carry = sum / 10;
    }
    return dummy.next;
  }
};