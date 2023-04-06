https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1

// DRY RUN SAME FOR 3 CHILD LIST ONLY TO UNDERSTAND RECURSIVE CALL.


//FLATTEN A LINKED LIST


//STEPS TO SOLVE PROBLEM
//STEP 1 — Base case
//STEP 2 — Set a pointer and Recursive calls for remaining portion to flatten a LL
//STEP 3 — Merge two sorted LL




Node* merge(Node* left, Node* right){
    //base cases
    if(left == NULL){
        return right;
    }
    if(right == NULL){
        return left;
    }
   
    Node* ans = new Node(-1);
    Node* temp = ans;
   
    while(left != NULL && right != NULL){
       
        if(left -> data < right -> data){
            temp -> child = left;
            temp = left;
            left = left -> child;
        }
        else{
            temp -> child = right;
            temp = right;
            right = right -> child;
        }
    }
   
    //If some elements are left in first LL
    while(left != NULL){
        temp -> child = left;
        temp = left;
        left = left -> child;
    }
   
    //If some elements are left in second LL
    while(right != NULL){
        temp -> child = right;
        temp = right;
        right = right -> child;
    }
   
    //Shifting ans pointer to correct position because there was a dummy node (-1) initially.
    ans = ans -> child;
   
    return ans;
}


Node* flattenLinkedList(Node* head)
{
    //base case
    if(head == NULL || head -> next == NULL){
        return head;
    }
   
    // tuc bas first case solve kro baaki recurion kr dvega.
    Node* down = head;                              // first list
    Node* right = flattenLinkedList(head -> next);  // second list (recursion right ton ek LL lai avega sort kra k.)
    head -> next = NULL;                            // disconnect first linked list
   
    // Finally, merge two lists.
    //Merging down and Right LL
    Node* ans = merge(down, right);
   
    return ans;
}







