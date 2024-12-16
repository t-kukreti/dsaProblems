// Done at leetcode
#include<iostream>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node* random;

    // constructor
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
        this->random = NULL;
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
void insert(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    tail->random = NULL;
    tail = temp;
}
void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main(){
    Node *newnode = new Node(7);
    Node* tail = newnode;
    Node* head = newnode;
    insert(tail , 13);
    insert(tail , 11);
    tail->next = head->next;
    head = head->next;
   
   



    return 0;
}