class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* curr = head;
       
        ListNode* first = head;
        ListNode* second = head;
       
        for(int i=1; i < left; i++)     first = first->next;
       
        ListNode* node = first;
        vector<int> arr;
        for(int i=0; i < right-left+1; i++) {
            arr.push_back(first->val);
            first = first->next;
        }
       
        reverse(arr.begin(), arr.end());
       
        for(int i=0; i<arr.size(); i++) {
            node->val = arr[i];
            node = node->next;
        }
        return head;
    }
};








// OPTIMISED


// DRY RUN FOR 1->2->3->4   left=2, right=3
// for this test case to understand properly
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // Base case
        if(!head || !head->next)    return head;
       
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* pre_it = NULL, *it = dummy;
       
        // Step 1: Traverse and get LeftNode & pre_LeftNode.
        for(int i=0; i < left; i++) {
            pre_it = it;
            it = it->next;
        }
       
        ListNode* prev = pre_it;
        ListNode* curr = it;            // mark pointer at left and pre_left.
       
        // Step 2: Reverse from left to right
        for(int i=left; i<=right; i++) {
            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
       
        // Step 3: Make connection with newHead i.e. 'prev'
        pre_it->next = prev;
        it->next = curr;
       
        return dummy->next;
    }
};

