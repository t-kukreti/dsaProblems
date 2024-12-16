#include<iostream>
using namespace std;
class deque{
    public:
    int *arr;
    int front;
    int rear;
    int size;

    deque(int size){
        this-> size = size;
        arr = new int [size];
        front = -1;
        rear = -1;
    }

    bool isEmpty(){
        if(front == -1 || rear == -1){
            return true;
        }
        return false;
    }
    void push_front(int data){
        if ((front == 0 && rear == size -1) || (front != 0 && rear == front - 1)){
            cout << "deque is full " << endl;
            return ;
        }
        else{
            // first member
            if(front == -1){
                front = rear = 0;
            }
            // pushing to front after first member
            else if (front == 0){
                front = size - 1;
            }
            // normal flow
            else{
                front --;
            }
            arr[front] = data;
        }
    }
    void push_back(int data){
        if ((front == 0 && rear == size -1) || (front != 0 && rear == front - 1)){
            cout << "deque is full " << endl;
            return ;
        }
        else{
            // first member
            if(front == -1){
                front = rear = 0;
            }
            // rear at last and first cell is empty
            else if (rear == size - 1 && front != 0){
                rear = 0;
            }
            // normal flow
            else{
                rear ++;
            }
            arr[rear] = data;
        }        
    }

    int pop_front(){
        if(isEmpty()){
            cout << "deque is empty " << endl;
            return -1;
        }
        int ans = arr[front];
        arr[front] = -1;
        if( front == rear ){
            front = rear = -1;
        }
        else if (front == size - 1){
            front = 0;
        }
        else{
            front ++;
        }
        return ans;
    }
    int pop_back(){
        if(isEmpty()){
            cout << "deque is empty " << endl;
            return -1;
        }
        int ans = arr[rear];
        arr[rear] = -1;
        if (front == rear){
            front = rear = -1;
        }
        else if (rear == 0){
            rear = size - 1;
        }
        else{
            rear --;
        }
        return ans;
    }
    int peek(){
        if(isEmpty()){
            cout << "deque is empty " << endl;
            return -1;
        }
        else{
            return arr[front];
        }
    }
};
int main(){
    deque d(3);
    d.push_front(1);
    d.push_front(2);
    int removed = d.pop_back();
    removed = d.pop_back();
    d.push_back(4);
    d.push_back(5);
    d.push_back(6);
    d.pop_front();
    d.pop_back();
    d.pop_back();
    cout << " removed element is " << removed << endl;
    cout << d.peek() << endl;
    
    return 0;
}