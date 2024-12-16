#include<iostream>
using namespace std;
class Node{
    public: 
    int data;
    Node *next;

    Node(int data){
        this-> data = data;
        this-> next = NULL;
    }
};
class stack{
    public:
    Node *top;
    stack(){
        top = NULL;
    }
    void push(int data){
        Node* temp = new Node(data);
        temp->next = top;
        top = temp;
    }
    bool isEmpty(){
        return top == NULL;
    }
    int pop(){
        if(!isEmpty()){
            Node* temp = top;
            top = top-> next;
            temp-> next = NULL;
            return temp->data;
        }
        return -1;
    }
    int peek(){
        if(!isEmpty()){
            return top->data;
        }
        return -1;
    }
};

int main() 
{
    stack st;
    st.push(2);
    st.push(3);
    int poppedElement = st.pop();
    poppedElement = st.pop();
    poppedElement = st.pop();
    cout << "popped element is: " << poppedElement << endl;
    cout << "element at top: " << st.peek() << endl;
}