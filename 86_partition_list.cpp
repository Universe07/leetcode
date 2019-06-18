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
  ListNode* partition(ListNode* head, int x) {
    ListNode lessHead(0);
    ListNode moreHead(0);
    ListNode* lessPtr = &lessHead;
    ListNode* morePtr = &moreHead;
    while (head) {
      if (head->val < x) {
        lessPtr->next = head;
        lessPtr = lessPtr->next;
      } else {
        morePtr->next = head;
        morePtr = morePtr->next;
      }
      head = head->next;
    }
    lessPtr->next = moreHead.next;
    morePtr->next = nullptr;
    return lessHead.next;
  }
};