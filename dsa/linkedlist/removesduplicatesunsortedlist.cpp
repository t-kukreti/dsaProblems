#include<iostream>
#include<map>
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
void Insertattail(Node* &tail , int d){
    Node *temp = new Node(d);
    tail ->next = temp;
    tail = temp;
    // tail = tail->next;
}
void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<< temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
}

Node* remove_duplicates (Node* head){
    if(head == NULL){
        return NULL;
    }
    map< int , int> visited;
    Node* curr = head;
    Node* prev = NULL;
    while(curr != NULL){
        if(visited[curr->data] > 0){
            cout<<curr->data << " has been repeated " << visited[curr->data]<<" times " << endl;
            prev->next = curr->next;
        }
        else{
            visited[curr->data]++;
            prev=curr;
        }
        curr=curr->next;
    }
    return head;

}
int main(){
      Node* node1 = new Node(4);
      Node* head = node1;
      Node* tail = node1;
      Insertattail(tail,2);
      Insertattail(tail,5);
      Insertattail(tail,4);
      Insertattail(tail,2);
      Insertattail(tail,2);
      print(head);
      cout<<"after removal : ";
      print(remove_duplicates(head));

    return 0;
}