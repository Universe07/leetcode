/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// merge sort
// Time: O(nlogn)
// Space: O(1)
class Solution {
 public:
  ListNode* sortList(ListNode* head) {
    if (!head || !head->next) return head;

    int len = 1;
    auto curr = head;
    while (curr = curr->next) ++len;

    ListNode dummy(0);
    dummy.next = head;
    ListNode* left;
    ListNode* right;
    ListNode* tail;
    for (int i = 1; i < len; i <<= 1) {
      curr = dummy.next;
      tail = &dummy;
      while (curr) {
        left = curr;
        right = split(curr, i);
        curr = split(right, i);
        auto merged = merge(left, right);
        tail->next = merged.first;
        tail = merged.second;
      }
    }
    return dummy.next;
  }
  ListNode* split(ListNode* head, int n) {
    while (--n && head) {
      head = head->next;
    }
    ListNode* rest = head ? head->next : nullptr;
    if (head) head->next = nullptr;
    return rest;
  }
  pair<ListNode*, ListNode*> merge(ListNode* l1, ListNode* l2) {
    ListNode dummy(0);
    auto tail = &dummy;
    while (l1 && l2) {
      if (l1->val > l2->val) swap(l1, l2);
      tail->next = l1;
      l1 = l1->next;
      tail = tail->next;
    }
    tail->next = l1 ? l1 : l2;
    while (tail->next) tail = tail->next;
    return {dummy.next, tail};
  }
};