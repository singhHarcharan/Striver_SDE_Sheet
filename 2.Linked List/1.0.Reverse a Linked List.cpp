// using stack
void reverseLL(Node** head)
{
    stack<Node*> s;
    Node* temp = *head;
    while (temp->next != NULL) {
        s.push(temp);
        temp = temp->next;
    }
    *head = temp;
    while (!s.empty()) {
        temp->next = s.top();
        s.pop();
        temp = temp->next;
    }
    temp->next = NULL;
}


// Iterative
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *forward = NULL;
       
        while(curr != NULL){
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
};




// Recursive.
class Solution {
public:
   
    ListNode* helper(ListNode* pre, ListNode* curr){
        if(curr){  
            ListNode* head = helper(curr, curr->next);
            curr->next = pre;
            return head;
        }
        return pre;
    }


    ListNode* reverseList(ListNode* head) {
        return helper(NULL, head);
   
    }
};
