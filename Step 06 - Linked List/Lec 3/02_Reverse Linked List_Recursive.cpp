// Question Link :- https://leetcode.com/problems/reverse-linked-list
// Reverse Linked List

// T.C = O(N)
// S.C = O(N)  (Recursive Stack Space)
class Solution {
public:
    ListNode* rev(ListNode* head, ListNode* prev) {
        if(!head) return prev;
        ListNode* forward = head->next;
        head->next = prev;
        return rev(forward, head);
    }

    ListNode* reverseList(ListNode* head) {
        return rev(head, NULL);
    }
};