https://leetcode.com/problems/rotate-list/

class Solution {
public:
    int getlen(ListNode* head) {
        int cnt = 0;
        while(head) {
            cnt++;
            head=head->next;
        }return cnt;
    }
   
    ListNode* gettail(ListNode* head) {
        while(head->next)   head = head->next;
        return head;
    }
   
    ListNode* rotateRight(ListNode* head, int k) {
       
        // Base case --- ONE Node LINKED LIST
        if(!head || !head->next)    return head;
       
        // Step 1: Find Length of linked List
        int len = getlen(head);
       
        // Step 2: Get Minimum Rotation we have to do.
        /* Coz if len is 5 and k = 100
        As, 100 is multiple of 5 so after rotation, it give original list
        Similarly, if k = 12, first 10 rotations will give us same list
        so we have to do only 2 rotation.
        */
        k = k % len;
        k = len-k;
       
        // Step 3: Make Linked List Circular
        ListNode* tail = gettail(head);
        tail->next = head;
       
        // Step 4: Iterate till size - k part and break the link.
        int cnt = 0;
        while(cnt < k) {
            tail = tail->next;
            cnt++;
        }
        head = tail->next;
        tail->next = nullptr;
        return head;
    }
};

