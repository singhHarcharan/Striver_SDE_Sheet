//Linked List


//Creating a Node for Linked List
//Insertion
//Deletion
//Linked List travesing


#include <iostream>


using namespace std;


class Node {
    public:
   
    int data;
    Node * next;
   
    Node(int new_data){
        this -> data = new_data;
        this -> next = NULL;
    }
   
    ~Node(){
        int value = this -> data;
       
        //memory free
        if(this -> next != NULL){
            delete next;
            this -> next = NULL;
        }
        cout << "Memory free for the value " << value << endl;
    }
};


void insertAtHead(Node * &head, int new_data){
    Node * temp = new Node(new_data);
   
    temp -> next = head;
    head = temp;
}


void insertAtTail(Node * & tail, int new_data){
    Node *temp = new Node(new_data);
   
    tail -> next = temp;
    tail = temp;
}


void insertAtPosition(int position, Node * & head, Node * &tail, int new_data){
    //Insertion at Start
    if(position == 1){
        insertAtHead(head, new_data);
        return;
    }
   
    Node * temp = head;
    int count = 1;
   
    while (count < position - 1){
        temp = temp -> next;
        count++;
    }
   
    //Insertion at tail
    if(temp -> next == NULL){
        insertAtTail(tail, new_data);
        return;
    }
   
    //Insertion at middle or specific position
    Node * nodeToInsert = new Node(new_data);
   
    nodeToInsert -> next = temp -> next;
    temp -> next = nodeToInsert;
}


void deleteNode(int position, Node * &head){
    //Deletion at Start
    if(position == 1){
        Node * temp = head;
       
        head = head -> next;
        temp -> next = NULL;
        //memory free for node
        delete temp;
    }
    //Deletion at Middle
    else{
        Node * previous = NULL;
        Node * current = head;
        int count = 1;
       
        while(count <= position){
            previous = current;
            current = current -> next;
            count++;
        }
        previous -> next = current -> next;
        current -> next = NULL;
        //memory free for Node.
        delete current;
    }
}


void print(Node * &head){
    Node * temp = head;
   
    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}


int main()
{
    //creating a node
    Node * node1 = new Node(10);
   
    //head pointer pointing to node1.
    Node * head = node1;
    Node * tail = node1;
   
    print(head);
   
    insertAtHead(head, 50);
    print(head);
   
    insertAtTail(tail, 100);
    print(head);
   
    insertAtPosition(4, head, tail, 200);
    print(head);
   
    deleteNode(2,head);
    print(head);
   
    return 0;
}



