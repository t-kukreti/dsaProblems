#include<iostream>
using namespace std;
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
void print(Node* tail){
    Node *temp = tail;
    if(tail==NULL){
        cout<<"List is empty " << endl;
        return ;
    }
    do{
        cout<<tail->data<<" ";
        tail = tail->next;
    } while(tail!=temp);
    cout<<endl;
}
void insertnode(Node* &tail , int element , int d){
    // Assuming element is present in the list 
    if(tail==NULL){
        Node* temp = new Node(d);
        tail = temp;
        temp->next = temp;
    }
    else{
        Node* currentnode = tail;
        while(currentnode->data != element){
            currentnode = currentnode->next;
        }
        Node* temp = new Node(d);
        temp->next = currentnode->next;
        currentnode->next = temp;
    }
}
void deletenode(Node* &tail,int element){
    if(tail==NULL){
        cout<<"No element is present in the list " << endl;
        return;
    }
    else{
        // assuming elment is present 
        Node* prev = tail;
        Node* current = prev->next;
        while(current->data != element){
            prev = current;
            current=current->next;
        }
        prev->next = current->next;
        // single node linked list
        if(current==prev){
            tail=NULL;
        }
        else if(tail==current){
            tail=prev;
        }
        current->next = NULL;
        delete current;
    }



}
bool iscircular(Node* head){
    if(head==NULL){
        return NULL;
    }
    Node * temp = head->next;
    while(temp != NULL && temp != head){
        temp=temp->next;
    }
    if(temp==head){
        return true;
    }
    return false;

}
int main(){
    Node* tail = NULL;
    insertnode(tail,1,10);
    print(tail);
    insertnode(tail,10,20);
    print(tail);
    insertnode(tail,10,15);
    insertnode(tail,10,25);
    insertnode(tail,10,35);
    print(tail);
    // deletenode(tail,10);
    print(tail);
    cout<<"tail is " << tail->data<<endl;
    // if(iscircular(tail)){
    //     cout<<"The list is circular " << endl;
    // }
    // else{
    //     cout<<"The list is not circular " << endl;
    // }
    
    return 0;
}