// Question Link :- https://leetcode.com/problems/rotate-list/
// Rotate List

// T.C = O(N)
// S.C = O(1)
class Solution {
public:
    int getLen(ListNode* head) {
        if(head == NULL) {
            return 0;
        }
        int cnt = 0;
        while(head) {
            cnt++;
            head = head->next;
        }
        return cnt;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) {
            return NULL;
        }
        int len = getLen(head);
        k %= len;

        ListNode* tail = head;
        while(tail->next != NULL) {
            tail = tail->next;
        }
        // connect tail with head
        tail->next = head;

        int br = len - k;
        while(br--) {
            tail = tail->next;
        }
        head = tail->next;
        tail->next = NULL;
        return head;
    }
};
