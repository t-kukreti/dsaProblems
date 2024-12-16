#include<iostream>
using namespace std;
class specialStack{
    public:
    int top;
    int size;
    int *arr;
    
    specialStack(int size){
        this->size = size;
        arr = new int [this->size];
        top = -1;
    }
    void push(int data){
        if(top < size-1){
            top++;
            arr[top] = data;
        }
        else{
            cout << "stack overflow " << endl;
        }
    }
    void pop(){
        if(top >= 0){
            top--;
        }
        else{
            cout << "stack underflow " << endl;
        }
    }
    int peek(){
        if(top >= 0){
            return arr[top];
        }
        else{
            cout << " stack is empty " << endl;
            return -1;
        }
    }
};

int main(){
    specialStack* st = new specialStack(5);
    st->push(5);
    st->push(6);
    return 0;
}