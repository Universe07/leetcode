/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
 public:
  void reorderList(ListNode* head) {
    if (!head || !head->next) return;
    ListNode* p = head;
    ListNode* pre = nullptr;
    while (p->next) {
      pre = p;
      p = p->next;
    }
    pre->next = nullptr;
    ListNode* nextP = head->next;
    reorderList(nextP);
    head->next = p;
    p->next = nextP;
  }
};