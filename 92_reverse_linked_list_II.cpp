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
  ListNode* reverseBetween(ListNode* head, int m, int n) {
    ListNode dummy(0);
    dummy.next = head;
    ListNode* prev = &dummy;
    for (int i = 0; i < m; ++i) {
      prev = prev->next;
    }
    auto head2 = prev;
    ListNode* rest = prev->next;
    prev = prev->next;

    for (int i = 0; i < n - m; ++i) {
      prev->next = rest->next;
      rest->next = head2->next;
      head2->next = rest;
      rest = prev->next;
    }
    return dummy.next;
  }
};