/*
    Easy And Brute Force Way:
    The Approach:
    Here in this approach, we use O(n) extra space for vector to store the linked list
    values and we simply return middle value of vector.


   
*/


// Hare and Tortoise algo
class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};
