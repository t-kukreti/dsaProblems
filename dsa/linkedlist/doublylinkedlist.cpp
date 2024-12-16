#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* previous;

    Node(int data){
        this->data = data;
        this->next = NULL;
        this->previous = NULL;
    }
     ~Node(){
        int value = this -> data ; 
        if(this->next != NULL){
            delete next;
            this -> next = NULL;
        }
        cout<<"Memory is free for node with data " << this->data << endl;
    }

};

void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data <<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int getlength(Node* head){
    Node *temp  = head;
    int len = 0;
    while(temp != NULL){
        len++;
        temp = temp->next;
    }
    return len;
}

void insertathead(Node * &tail, Node * &head,int d){
    // if it's an empty list 
    if(head==NULL){
        Node * temp = new Node (d);
        head = temp;
        tail = temp;
    }
    else{
    Node * temp = new Node(d);
    temp -> next = head;
    head ->previous = temp;
    head = temp;
    }
}
void insertattail(Node* &tail ,Node * &head, int d){
    // if it's an empty list 
    if(tail==NULL){
        Node *temp = new Node(d);
        tail = temp;
        head = temp;
    }
    else{
    Node *temp = new Node (d);
    tail->next = temp;
    temp->previous = tail;
    tail = temp;
    }
}
void insertatposition(Node* &tail,Node* &head,int position,int d){
// inserting at first position 
    if(position == 1){
        insertathead(tail,head,d);
        return;
    }

    Node * currentnode = head;
    int count = 1;
    while(count < position-1){
        currentnode = currentnode->next;
        count++;
    }
// inserting at last position 
    if(currentnode->next == NULL){
        insertattail(tail,head,d);
        return;
    }
// any other location 
    Node * nodetoinsert = new Node(d);
    nodetoinsert->next = currentnode->next;
    currentnode->next->previous = nodetoinsert;
    currentnode->next = nodetoinsert;
    nodetoinsert->previous = currentnode;
}
void deleteatposition(Node* &tail, Node* &head,int position){
    // Deleting at first position 
    if(position == 1){
        Node* temp = head;
        temp->next->previous=NULL;
        head = temp->next;
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
        previous->next=NULL;
        current->next=NULL;
        current->previous=NULL;
        tail = previous;
        delete current;
        return;
     }
    previous->next = current -> next;
    current->next->previous = previous->next; // can work even without this
    current->previous=NULL;
    current -> next = NULL;
    delete current;    
    }
}
Node* floydcycledetection(Node* head){
         if(head==NULL){
            return NULL;
        }
        Node*fast = head;
        Node*slow = head;
         while(slow != NULL && fast != NULL && fast->next!=NULL && fast->next->next!=NULL){
            fast = fast->next;
            if(fast!=NULL){
                fast = fast->next;
            }
            slow = slow->next;
            if(slow==fast){
                cout<<"cycle is present "<< endl;
                return fast;
            }
    }
    cout<<"cycle is absent " << endl;
    return NULL;

    }
    Node *detectCycle(Node *head) {
        Node* intersection = floydcycledetection(head);
        Node* temp = head;
        while(temp!=intersection){
            temp=temp->next;
            intersection=intersection->next;
        }
        return intersection;
    }
    // delete a cycle set starting cycle index to NULL
    void deletecycle(Node *head){
        Node* temp = detectCycle(head);
        temp->next=NULL;
    }

int main(){
    // creation of a doubly linked list
    // Node* node1 = new Node(2);
    // Node* head = node1;
    // Node* tail = node1;
    Node* head = NULL;
    Node* tail = NULL;
    insertathead(tail,head,1);
    insertattail(tail,head,4);
    // print(head);
    // insertatposition(tail,head,3,3);
    // print(head);
    // insertatposition(tail,head,4,5);
    // insertattail(tail,head,6);
    // print(head);
    tail->next = head->next;
    cout<<"head " << head->data << " tail " << tail->data<< endl;
    Node* ans = detectCycle(head);
    cout<<ans->data<<endl;
    deletecycle(head);
    cout<<"after deletion "<<endl;
    floydcycledetection(head);
   
   





    // deleteatposition(tail,head,4);
    // print(head);
    // cout<<"head " << head->data << endl;
    // cout<<"tail " << tail->data << endl;
    // cout<<"length of doubly linked list " << getlength(head)<<endl;
 
   
    return 0;
}