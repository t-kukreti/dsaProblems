// It's done with recursion code is in PC
#include<iostream>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node *child;

    // constructor
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
        this->child = NULL;
    }
    // Destructor
    ~Node()
    {
        int value = this->val;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "Memory is free for node with val " << this->val << endl;
    }
};
void Insertattail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
}
void insertchild(Node* &tail , int d){
    Node* temp = new Node(d);
    tail->child = temp;
    tail = temp;

}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        Node* tempchild = temp->child;
        while(tempchild != NULL){
            cout<<tempchild->val<<" ";
            tempchild = tempchild->child;
        }

        temp = temp->next;
    }
    cout << endl;
}
Node* flattenedlist(Node* head){
    Node* tail = head;
    Node* temp = head;
    while(temp != NULL){
        Node* l1 = temp->child;
        Node* l2 = temp->next;

        while(l1 != NULL){
            if(l1->val <= l2->val){
                tail->child = l1;
                tail = l1;
                l1 = l1->child;
                
            }
            else{
                tail->child = l2;
                tail = l2;
                l2 = l2->child;
            }

        }
        temp = temp->next;
    }
    return head;

}

int main(){
    Node* newnode = new Node(3);
    Node* tail = newnode;
    Node* head = newnode;
    Insertattail(tail , 5);
    Insertattail(tail , 22);
    tail = head;
    insertchild(tail , 4);
    insertchild(tail , 6);
    tail = head->next;
    insertchild(tail,11);
    insertchild(tail,14);
    tail = head->next->next;
    insertchild(tail,25);
    cout<<"Unflattened list :";
    print(head);
    cout<<"Flattened sorted list :";
    print(flattenedlist(head));
    return 0;
}