// Time: O(nlogn) for using STL set
// space: O(n) for using STL set
class Solution {
 public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    set<ListNode *> node_set;
    while (headA) {
      node_set.insert(headA);
      headA = headA->next;
    }
    while (headB) {
      if (node_set.find(headB) != node_set.end()) {
        return headB;
      }
      headB = headB->next;
    }
    return NULL;
  }
};

// Time:

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
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int lenA = getLength(headA), lenB = getLength(headB);

    if (lenA > lenB) {
      headA = forwardList(headA, lenB, lenA);
    } else {
      headB = forwardList(headB, lenA, lenB);
    }

    while (headA && headB) {
      if (headA == headB) {
        return headA;
      }
      headA = headA->next;
      headB = headB->next;
    }
    return NULL;
  }

  int getLength(ListNode *head) {
    int i = 0;
    while (head) {
      i = i + 1;
      head = head->next;
    }
    return i;
  }
  ListNode *forwardList(ListNode *head, int shortLength, int longLength) {
    int delta = longLength - shortLength;
    while (delta > 0) {
      head = head->next;
      delta--;
    }
    return head;
  }
};