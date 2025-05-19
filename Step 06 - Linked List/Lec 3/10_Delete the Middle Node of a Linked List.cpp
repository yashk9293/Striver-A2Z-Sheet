// Question Link :- https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/
// Delete the Middle Node of a Linked List

// T.C = O(n)
// S.C = O(1)
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(!head || !head->next) {
            return NULL;
        }
        ListNode* slow = head;
        ListNode* fast = head->next->next;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* toDelete = slow->next;
        slow->next = slow->next->next;
        delete(toDelete);
        
        return head;
    }
};