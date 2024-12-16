#include<iostream>
using namespace std;
class queue{
    public:
    int *arr;
    int front;
    int rear;
    int size;

    queue(int size){
        this-> size = size;
        arr = new int[size];
        front = rear = 0;
    }
    bool isEmpty(){
        if(rear == 0){
            return true;
        }
        else{
            return false;
        }
    }
    void push(int data){
        if(rear == size){
            cout << "queue is full " << endl;
            return ;
        }   
        else{
            arr[rear] = data;
            rear ++;
        }
    }
    int pop(){
        if(isEmpty()){
            cout << "queue is empty " << endl;
            return -1;
        }
        int ans;
        if (front == rear){
            front = 0;
            rear = 0;
        }
        else{
            ans = arr[front];
            arr[front] = -1;
            front ++;
        }
        return ans;
    }
    int peek(){
        if(front != size){
            return arr[front];
        }
        return -1;
    }
};
int main(){
    queue q(4);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    int removedelement = q.pop();
    removedelement = q.pop();
    removedelement = q.pop();
    removedelement = q.pop();
    removedelement = q.pop();
    cout << "element at first " << q.peek()
     << "element removed " << removedelement << endl;
    q.push(5);
    cout << "new data " << q.peek() << endl;
    return 0;
}