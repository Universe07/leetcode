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
  ListNode* insertionSortList(ListNode* head) {
    ListNode dummy(INT_MIN);
    ListNode* pos = nullptr;
    auto curr = head;
    while (curr) {
      pos = findInsertionPoint(&dummy, curr->val);
      auto tmp = curr->next;
      curr->next = pos->next;
      pos->next = curr;
      curr = tmp;
    }
    return dummy.next;
  }
  ListNode* findInsertionPoint(ListNode* head, int val) {
    ListNode* prev = nullptr;
    for (auto curr = head; curr && curr->val <= val;
         prev = curr, curr = curr->next) {
    }
    return prev;
  }
};