// Question Link :- https://leetcode.com/problems/middle-of-the-linked-list
// Middle of the Linked List

// Brute Force
// T.C = O(n)
// S.C = O(1)
class Solution {
public:
    int getLength(ListNode *head) {
        int len=0;
        while(head != NULL) {
            len++;
            head = head -> next;
        }
        return len;
    }

    ListNode* middleNode(ListNode* head) {
        int len = getLength(head);
        int ans = (len/2);

        ListNode *temp = head;
        int cnt = 0;
        while(cnt < ans) {
            temp = temp -> next;
            cnt++;
        }
        return temp;
    }
};



// Tortoise and Hare Approach
// T.C = O(n)
// S.C = O(1)
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow  = head;
        ListNode* fast = head;
        
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        } 
        return slow;
    }
};