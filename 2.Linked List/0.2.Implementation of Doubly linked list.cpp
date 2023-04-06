//Doubly Linked List


//Insertion
//Traversal
//Deletion




#include <iostream>
using namespace std;


class Node{
    public:
   
    int data;
    Node *previous;
    Node *next;
   
    //constructor
    Node(int new_data){
        this -> data = new_data;
        this -> previous = NULL;
        this -> next = NULL;
    }
   
    //Destructor
    ~Node(){
        int value = this -> data;
        if(this -> next != NULL){
            delete next;
            next = NULL;
        }
        cout << "Memory free for node with data " << this -> data << endl;
    }
};


void insertAtHead(Node * &head,Node * &tail, int new_data){
    //If list is empty in initial.
    if(head == NULL){
        Node *temp = new Node(new_data);
       
        head = temp;
        tail = temp;
    }
    else{
        Node *temp = new Node(new_data);
   
        temp -> next = head;
        head -> previous = temp;
        head = temp;
    }
}


void insertAtTail(Node * &head,Node *&tail, int new_data){
   
    //If the  list is empty in initial
    if(tail == NULL){
        Node *temp = new Node(new_data);
       
        head = temp;
        tail = temp;
    }
    else{
        Node *temp = new Node(new_data);
       
        tail -> next = temp;
        temp -> previous = tail;
        tail = temp;
    }
}


void insertAtPosition(int position, Node *&head, Node *&tail, int new_data){
    //Insertion at Start
    if(position == 1){
        insertAtHead(head, tail, new_data);
        return;
    }
   
    Node *temp = head;
    int count = 1;
   
    while(count < position - 1){
        temp = temp -> next;
        count++;
    }
    //Insertion at End
    if(temp -> next == NULL){
        insertAtTail(head, tail, new_data);
            return;
        }
   
    //creating a node for new_data
    Node * nodeToInsert = new Node(new_data);
   
    nodeToInsert -> next = temp -> next;
    temp -> next -> previous = nodeToInsert;
    temp -> next = nodeToInsert;
    nodeToInsert -> previous = temp;
}


void deleteNode(int position, Node * &head, Node* &tail){
    //Deletion at Start
    if(position == 1){
        Node * temp = head;
       
        temp -> next -> previous = NULL;
        head = temp -> next;
        temp -> next = NULL;
       
        //memory free for node
        delete temp;
    }
    //Deletion at Middle
    else{
        Node * previous = NULL;
        Node * current = head;
        int count = 1;
       
        while(count < position){
            previous = current;
            current = current -> next;
            count++;
        }
       
        current -> previous = NULL;
        previous -> next = current -> next;
        current -> next = NULL;
       
        //updating the tail
        if(previous -> next == NULL){
            tail = previous;
        }
       
        //memory free for Node.
        delete current;
    }
}




void print(Node *&head){
   
    Node *temp = head;
    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}


int getLength(Node *head){
    int length = 0;
    Node *temp = head;
   
    while(temp != NULL){
        length++;
        temp = temp -> next;
    }
    return length;
}




int main()
{
    //Node *node1 = new Node(10);
   
    // Node *head = node1;
    // Node *tail = node1;
    //print(head);
   
    //If the List is empty in initial.That means
    Node *head = NULL;
    Node *tail = NULL;
   
   
    //cout << "length of the Linked List is " << getLength(head) << endl;
   
    insertAtHead(head, tail, 9);
    print(head);
   
    insertAtTail(head, tail, 11);
    print(head);
   
    insertAtTail(head, tail, 13);
    print(head);
   
    insertAtTail(head, tail, 14);
    print(head);
   
    insertAtPosition(2 ,head, tail, 12);
    print(head);
   
    deleteNode(5,head, tail);
    print(head);
    cout << "Head " << head -> data << endl;
    cout << "Tail " << tail -> data << endl;


    return 0;
}



