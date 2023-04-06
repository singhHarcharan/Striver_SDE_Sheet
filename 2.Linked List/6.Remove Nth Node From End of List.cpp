// time : O(N) + O(N)
class Solution {
public:
    int getlen(ListNode* head) {
        int cnt = 0;
        while(head) {
            cnt++;
            head = head->next;
        }return cnt;
    }
   
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = getlen(head);
       
        // edge case
        if(len == n) {
            ListNode* nodeToDel = head;
            head = head->next;
            nodeToDel->next = NULL;
            return head;
        }
       
        ListNode* curr = head;
        int cnt = 1;
        while(cnt != len-n) {
            cnt++;
            curr = curr->next;
        }
       
        ListNode* node_to_del = curr->next;
        curr->next = node_to_del->next;
        return head;
    }
};




// Using slow & fast pointer approach
// time : O(N)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head, *fast = head;


        // Maintain the gap of 'n' between slow and fast & then
        // move fast till fast->next != NULL single step only.
        for(int i=1; i <= n; i++)
            fast = fast->next;
       
        // when totalNode == n
        // means we have to delete first node.
        if(fast == NULL)    return head->next;
       
        while(fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};
