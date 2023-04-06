https://leetcode.com/problems/intersection-of-two-linked-lists/

// 1. HashMap Solution
// Time Complexity : O(m + n)
// Space Complexity : O(m)
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*, int> m;
        while(headA != NULL){
            m[headA]++;
            headA = headA -> next;
        }
        while(headB != NULL){
            if(m[headB] > 0){
                return headB;
            }
            headB = headB -> next;
        }
        return NULL;
    }
};


// 2. Length Difference Solution
// Time Complexity : O(m + n)
// Space Complexity : O(1)
class Solution {
public:
    int getlen(ListNode* head) {
        int cnt = 0;
        while(head) {
            cnt++;
            head = head->next;
        }return cnt;
    }
   
    void getHead(ListNode* & head, int diff) {
        while(diff) {
            head = head->next;
            diff--;
        }
    }
   
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
       
        // Step1 : Get Len from both pointers.
        int len1 = getlen(headA);
        int len2 = getlen(headB);
       
        // Step 2: Match both pointers according to the length.
        if(len1 > len2) getHead(headA, len1-len2);
        else            getHead(headB, len2-len1);
       
        // Step 3: Traverse untill we don't get same Node at both pointers.
        while(headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }return headA;
    }
};


// 3. Two-Pointers Solution
// Time Complexity : O(m + n)
// Space Complexity : O(1)
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
       
        ListNode* a = headA;
        ListNode* b = headB;
       
        while(a != b) {
            if(a == NULL)   a = headB;
            else            a = a->next;
           
            if(b == NULL)   b = headA;
            else            b = b->next;
        }return a;
    }
};

