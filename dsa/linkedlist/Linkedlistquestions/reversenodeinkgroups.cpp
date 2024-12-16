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
int getlength(Node * head){
    int len=0;
    while(head!=NULL){
        len++;
        head=head->next;
    }
    return len;
}
Node* reversekgroups(Node* head,int k,int length){
          if(head==NULL){
            return NULL;
        }
        // reverse first k nodes
        Node* prev = NULL;
        Node* next = NULL;
        Node* curr = head;
        int cnt = 0;
        while(curr!= NULL && cnt<k){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            cnt++;
        }
        int remainingnodes= length-cnt;
        if(remainingnodes >= k){
             // recursion 
        if(next!=NULL){
            head->next = reversekgroups(next,k,remainingnodes);
        }
        return prev; 
        }
        else{
            head->next = curr;
        }
        return prev;
       

}
void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<< temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
}
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
int main(){
    int k;
    cout<<"Enter k ";
    cin>>k;
    Node* firstnode = new Node(1);
    Node* head = firstnode;
    Node* tail = firstnode;
    Insertattail(tail,2);
    Insertattail(tail,3);
    Insertattail(tail,4);
    Insertattail(tail,5);
    // Insertattail(tail,2);
    int length = getlength(head);
    cout<<"length of list is " << length << endl;
    cout<<"Before reversing in k groups " << endl;
    print(head);
   Node * ans =  reversekgroups(head,k,length);
   cout<<"after " <<endl;
    print(ans);
// leetcode testcase 50 failed idk why check that out
    

    
    return 0;
}