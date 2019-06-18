// Time: O(n)
// Space: O(1)
class Solution {
 public:
  ListNode* reverseBetween(ListNode* head, int m, int n) {
    ListNode dummy(0);
    dummy.next = head;
    ListNode* prev = &dummy;
    for (int i = 0; i < m - 1; ++i) {
      prev = prev->next;
    }
    auto head2 = prev;
    prev = prev->next;
    ListNode* rest = prev->next;

    for (int i = 0; i < n - m; ++i) {
      prev->next = rest->next;
      rest->next = head2->next;
      head2->next = rest;
      rest = prev->next;
    }
    return dummy.next;
  }
};