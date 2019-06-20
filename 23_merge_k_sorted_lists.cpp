/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Time: O(n*logk)
// Space: O(1)
class Solution {
 public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.empty()) return nullptr;
    int left = 0, right = lists.size() - 1;
    while (right > 0) {
      if (left >= right) {
        left = 0;
      } else {
        lists[left] = mergeTwoLists(lists[left], lists[right]);
        ++left;
        --right;
      }
    }
    return lists[0];
  }
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode dummy(0);
    auto curr = &dummy;
    while (l1 && l2) {
      if (l1->val > l2->val) swap(l1, l2);
      curr->next = l1;
      l1 = l1->next;
      curr = curr->next;
    }
    curr->next = l1 ? l1 : l2;
    return dummy.next;
  }
};