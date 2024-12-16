#include<iostream>
using namespace std;

class queue{
    public:
    int *arr;
    int size;
    int front;
    int rear;

    queue(int n){
        size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    int push(int data){
        if ((front == 0 && rear == size-1) || (rear == ((front - 1) % (size -1)))){
            cout << "queue is full " << endl;
            return -1;
        }
        else if (front == -1){
            front = rear = 0;
        }
        else if (rear == size-1 && front != 0){
            rear = 0;
        }
        else{
            rear++;
        }
        arr[rear] = data;
        return 0;
    }

    int pop(){
        if (front == -1){
            cout << "queue is empty " << endl;
            return 0;
        }
        int ans = arr[front];
        arr[front] = -1;
        if (front == rear){
            front = rear = -1;
        }
        else if (front == size-1){
            front = 0;
        }
        else{
            front++;
        }
        return ans;
    }
    int frontel(){
        if(front == -1){
            cout << "queue is empty " << endl;
            return -1;
        }
        return arr[front];
    }
};


int main(){
    queue q(4);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    cout << "first element " << q.frontel() << endl;
    return 0;
}