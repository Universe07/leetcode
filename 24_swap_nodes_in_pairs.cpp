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
  ListNode* swapPairs(ListNode* head) {
    ListNode dummy{0};
    dummy.next = head;
    auto curr = &dummy;
    while (curr->next && curr->next->next) {
      auto next_1 = curr->next;
      auto next_2 = next_1->next;
      auto next_3 = next_2->next;
      curr->next = next_2;
      next_2->next = next_1;
      next_1->next = next_3;
      curr = next_1;
    }
    return dummy.next;
  }
};