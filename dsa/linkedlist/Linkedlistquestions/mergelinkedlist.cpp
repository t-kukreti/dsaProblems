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

// this was love babbar dsa code but it didn't pass one test case but the one i wrote in leetcode passed all cases in codestudio
Node *solve(Node *first, Node *second)
{
    // only one element is present in first list
    if (first->next == NULL)
    {
        first->next = second;
    }

    Node*curr1 = first;
    Node*next1 = curr1->next;
    Node*curr2 = second;
    Node*next2 = curr2->next;

    while (next1 != NULL && curr2 != NULL)
    {
        if ((curr2->data >= curr1->data) && (curr2->data <= next1->data))
        {
            curr1->next = curr2;
            next2 = curr2->next;
            curr2->next = next1;
            curr1 = curr2;
            curr2 = next2;
        }
        else
        {
            curr1 = next1;
            next1 = next1->next;

            if (next1 == NULL)
            {
                curr1->next = curr2;
                return first;
            }
        }
    }
    return first;
}
Node *mergetwosortedlist(Node *first, Node *second)
{
    if (first == NULL)
        return second;

    if (second == NULL)
        return first;

    if (first->data <= second->data)
    {
        return solve(first, second);
    }
    else
    {
        return solve(second, first);
    }
}

int main()
{
    Node* first = new Node(1);
    Node* tail1 = first;
    Node* second = new Node(4);
    Node* tail2 = second;

    Insertattail(tail1 , 5);
    Insertattail(tail2,5);
    Insertattail(tail2,6);

    cout<<"This is your first list : "; 
    print(first);
    cout<<"This is your second list : "; 
    print(second);
    cout<<"This is your list after merging : ";
    Node* mergedlisthead = mergetwosortedlist(first , second);
    print(mergedlisthead);

    return 0;
}