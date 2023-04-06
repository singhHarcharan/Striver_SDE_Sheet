https://leetcode.com/problems/linked-list-cycle/

class Solution {
public:
    bool hasCycle(ListNode *head) {
       
        ListNode* slow = head, *fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)    return true;
        }return false;
    }
};






// Return starting Node of Loop in Linked List
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
       
        unordered_map<ListNode*, bool> visited;
        while(head != NULL){
            if(visited[head] == true){
                return  head;
            }
            visited[head] = true;
            head = head->next;
        }
        return NULL;
    }
};


class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
       
        ListNode* slow = head, *fast = head;
       
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
           
            // Cycle detected, start 'slow' from beginning again to get
            // starting point of the loop
            if(slow == fast) {
                slow = head;
                while(fast != slow) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }return nullptr;
    }
};

