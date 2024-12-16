                        NOT COMPLETED YET AND NOT FULLY UNDERSTOOD YET   
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    // Destructor
    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "Memory is free for node with data " << this->data << endl;
    }
};
void Insertattail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
    // tail = tail->next;
}
void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
 
                // Function for merge sort 
Node* merge (Node* n1 , Node* n2){

}

void mergesort(Node** head){
    // base case
    if(*head == NULL || (*head)->next == NULL){
        return ;
    }
    Node* sublist1;
    Node* sublist2;

    divide(*head, &sublist1, &sublist2);
    mergesort(&sublist1);
    mergesort(&sublist2);

    // merge 
    *head = merge(sublist1 , sublist2);
}
void divide(Node* head , Node** sublist1 , Node** sublist2){
    int len = 0;
    Node* curr = head;
    while(curr!=NULL){
        len++;
        curr=curr->next;
    }
    int mid = len/2;
    curr = head;
    Node* prev = NULL;
    for(int i = 0 ; i < mid ; i++){
        prev = curr;
        curr = curr->next;
    }

    if(prev!=NULL){
        prev->next = NULL;
    }
    *sublist1 = head;
    *sublist2 = curr;  
}


int main()
{
    Node *node1 = new Node(4);
    Node *head = node1;
    Node *tail = node1;
    Insertattail(tail, 2);
    Insertattail(tail, 5);
    Insertattail(tail, 4);
    Insertattail(tail, 2);
    Insertattail(tail, 2);
    print(head);
    return 0;
}