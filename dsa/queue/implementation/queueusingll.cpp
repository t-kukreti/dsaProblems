#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }   
};
class queue{
    public:
    Node* front;
    Node* rear;

    queue(){
        front = NULL;
        rear = NULL;
    }
    bool isEmpty(){
        if(front == NULL){
            return true;
        }
        return false;
    }
    void push(int data){
        Node* temp = new Node(data);
        // if first element 
        if(front == NULL){
            temp-> next = rear;
            temp-> prev = NULL;
            front = rear = temp;
        }
        else{
            temp-> next = rear;
            rear-> prev = temp;
            rear = temp;
        }
    }
    int pop(){
        if(isEmpty()){
            cout << " queue is empty " << endl;
            return -1;
        }
            int ans = front-> data;
            if(front == rear){
                front-> next = NULL;
                front = rear = NULL;
            }
            else{
                Node* temp = front;
                front = front-> prev;
                temp-> next = NULL;
            }
        return ans;
    }
    int peek(){
        if(isEmpty()){
            cout << " queue is empty " << endl;
            return -1;
        }
        else{
            return front->data;
        }
    }
};
int main(){
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    int removed = q.pop();
    removed = q.pop();
    removed = q.pop();    
    q.push(4);
    removed = q.pop();

    cout << " first element is " << q.peek() << endl;
    cout << " removed element is " << removed << endl;


    return 0;
}