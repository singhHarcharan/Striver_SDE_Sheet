// Iterative
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Base case
        if(!list1)  return list2;
        if(!list2)  return list1;
       
        ListNode* ptr = NULL;
        if(list1->val <= list2->val) {
            ptr = list1;
            list1 = list1->next;
        }
        else {
            ptr = list2;
            list2 = list2->next;
        }
       
        ListNode* curr = ptr;
       
        // till one of the list doesn't reaches NULL
        while(list1 && list2) {
            if(list1->val <= list2->val) {
                curr->next = list1;
                list1 = list1->next;
            }
            else {
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }
       
        // adding remaining elements of bigger list.
        if(!list1)  curr->next = list2;
        else        curr->next = list1;
       
        return ptr;
    }
};




// RECURSIVE
class Solution {
public:
    ListNode* solve(ListNode *first, ListNode* second) {
        // Base case
        if(!first)  return second;
        if(!second) return first;
       
        if(first->val <= second->val) {
            first->next = solve(first->next, second);
            return first;
        }
        else {
            second->next = solve(first, second->next);
            return second;
        }
    }
   
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        return solve(list1, list2);
    }
};
