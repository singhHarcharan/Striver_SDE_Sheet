https://leetcode.com/problems/palindrome-linked-list/

// Brute force using extra space.
class Solution {
public:
    vector<int> list_to_array(ListNode* head) {
        vector<int> arr;
        while(head){
            arr.push_back(head->val);
            head = head->next;
        }return arr;
    }
   
    ListNode* reverse_list(ListNode* head) {
        ListNode * prev = NULL, *curr = head, *forward = NULL;
        while(curr) {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }return prev;
    }
   
    ListNode* recursive_reverse(ListNode* prev, ListNode* curr) {
        if(curr) {
            ListNode* head = recursive_reverse(curr, curr->next);
            curr->next  = prev;
            return head;
        }return prev;
    }
   
    bool isPalindrome(ListNode* head) {
        vector<int> original = list_to_array(head);
       
        ListNode* newHead = recursive_reverse(NULL, head);
       
        vector<int> reversed_array = list_to_array(newHead);
       
        return original == reversed_array;
    }
};






// WITHOUT EXTRA SPACE
class Solution {
public:
    void getMid(ListNode* &head, ListNode* &mid, ListNode* &prev) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        mid = slow;
    }
   
    ListNode* reverse(ListNode* head) {
        ListNode* curr = head, *prev = NULL, *forward = NULL;
        while(curr) {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }return prev;
    }
   
    ListNode* recursiveReverse(ListNode* prev, ListNode* curr) {
        if(curr) {
            ListNode* newHead = recursiveReverse(curr, curr->next);
            curr->next = prev;
            return newHead;
        }return prev;
    }
   
    bool isPalindrome(ListNode* head) {
        // Base case
        if(!head->next) return true;
       
        // step 1: getMid.
        ListNode* mid = NULL, *prev = NULL;
        getMid(head, mid, prev);
       
        // Step 2: Break the link after Mid and reverse second half
        ListNode* head2 = mid;
        prev->next = NULL;
       
        ListNode* h1 = head;
        ListNode* h2 = recursiveReverse(NULL, head2);
       
        // step 3: start comparing two lists one by one.
        while(h1 && h2) {
            if(h1->val != h2->val)     return false;
            h1 = h1->next;
            h2 = h2->next;
        }
        return true;
    }
};



