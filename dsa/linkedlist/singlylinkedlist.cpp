#include<iostream>
using namespace std;
// Creation of Node 
class Node{
    public:
    int data;
    Node* next;

 // constructor
    Node(int data){
        this -> data = data;
        this ->next = NULL;

    }
    // Destructor 
    ~Node(){
        int value = this -> data ; 
        if(this->next != NULL){
            delete next;
            this -> next = NULL;
        }
        cout<<"Memory is free for node with data " << this->data << endl;
    }
};

void Insertathead(Node* &head , int d){
    // Reference is taken so that changes happen in the original linked list , and a copy is not made 
    // create new node
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}
void Insertattail(Node* &tail , int d){
    Node *temp = new Node(d);
    tail ->next = temp;
    tail = temp;
    // tail = tail->next;
}
void Insertatposition(Node* &tail, Node* &head,int position , int d){
    // Inserting at first position 
    if(position == 1){
        Insertathead(head,d);
        return ;
    }
    Node *temp = head;
    int count = 1;
    while(count < position-1){
        temp = temp->next;
        count++;
    }
    // Inserting at last position 
    if(temp -> next == NULL){
        Insertattail(tail,d);
        return ;
    }
    // Creating a node 
    Node *nodetoinsert = new Node(d);
    nodetoinsert -> next = temp -> next;
    temp->next = nodetoinsert;
}
void deleteatposition(Node* &tail, Node* &head,int position){
    // Deleting at first position 
    if(position == 1){
        Node* temp = head;
        head = head->next;
        temp -> next = NULL;
        delete temp;
    }
    // Deleting at middle or any position 
    else{
    Node* current = head;
    Node* previous = NULL;
    int count = 1; 
    while(count < position){
        previous = current;
        current = current -> next;
        count++;
    }
    // check if, to be deleted node is the last node 
    if(current->next == NULL){
        tail = previous;
    //     previous->next = current -> next;
    //     current -> next = NULL;
    //     delete current;  
     }
    previous->next = current -> next;
    current -> next = NULL;
    delete current;    
    }
}
// Deletion with the help of value 

// void deleteatposition1(Node* &tail, Node* &head,int value){
//     // Deleting at first position 
//     if(value==head->data){
//         Node* temp = head;
//         head = head->next;
//         temp -> next = NULL;
//         delete temp;
//     }
//     // Deleting at middle or any position 
//     else{
//     Node* current = head;
//     Node* previous = NULL;
//     while(current->data != value){
//         previous = current;
//         current = current -> next;
//     }
//     // check if, to be deleted node is the last node 
//     if(current->next == NULL){
//         tail = previous;
//     //     previous->next = current -> next;
//     //     current -> next = NULL;
//     //     delete current;  
//      }
//     previous->next = current -> next;
//     current -> next = NULL;
//     delete current;    
//     }
// }

void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<< temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
}
int main(){
    // dynamic allocation
    // created a new node 
    Node* node1 = new Node(10);
    // cout << node1 -> data <<endl;
    // cout << node1 -> next <<endl;

    // head pointed to node1 
    Node* head = node1;
    Node* tail = node1;
    cout<<"Before inserting a node " << endl;
    // print(head);
    // Insertathead(head,12);
    // cout<<"after inserting a new node " << endl;
    // print(head);
    // Insertathead(head,15);
    // print(head);
    print(head);
    cout<<"after inserting a new node " << endl;
    Insertattail(tail,12);
    print(head);
    Insertattail(tail,15);
    print(head);
    Insertattail(tail,20);
    print(head);

    Insertatposition(tail,head,4,22);
    print(head);
    deleteatposition(tail,head,5); // this is done by position

    // deleteatposition1(tail,head,20); this is done by value 
    print(head);
    cout<<"Head " << head -> data << " " << " Tail " << tail -> data << endl;
    return 0;
}
/* 
   Homework :-
    1. Try to do deletion with value , and understand destructor (done)
    2. Set tail to right position after deletion of last node (done)
*/ 