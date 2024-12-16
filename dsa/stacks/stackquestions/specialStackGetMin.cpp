#include<iostream>
#include<stack>
using namespace std;
// space optimised approach tc O(1), sc O(1)
class specialStack{
    stack<int> s;
    int mini;

    public:
    void push(int data){
        // for first element
        if(s.empty()){
            s.push(data);
            mini = data;
        }
        else{
            if(data < mini){
                s.push(2* data - mini);
                mini = data;
            }
            else{
                s.push(data);
            }
        }
    }
    int pop(){
        if(s.empty()){
            return -1;
        }
        int curr = s.top();
        s.pop();

        if(curr > mini){
            return curr;
        }
        else{
            int prevMini = mini;
            int val = 2* mini - curr;
            mini = val;
            return prevMini;
        }
    }
    int top(){
        if(s.empty()){
            return -1;
        }
        int curr = s.top();
        if(curr < mini){
            return mini;
        }
        else{
            return curr;
        }
    }
    bool isEmpty(){
        return s.empty();
    }
    int getMin(){
        if(s.empty()){
            return -1;
        }
        else{
            return mini;
        }
    }
};
// with space complexity having O(n), tc O(1)
class stack2{
    public: 
    stack<int> st;
    stack<int> minStack;
    int min;

    void push(int data){
        // for first element, make it the minimum element
        if(st.empty()){
            st.push(data);
            min = data;
            minStack.push(min);
        }
        // compare it with new data values if smaller update mini 
        else{
            if(data < min){
                st.push(data);
                min = data;
                // store min values in new stack.
                minStack.push(min);
            }
            else{
                st.push(data);
                minStack.push(min);
            }
        }
    }
    int pop(){
        // pop from both stack so minimum element is always on the top
        if(!st.empty()){
            st.pop();
            minStack.pop();
        }
        return -1;
    }
    int top(){
        if(st.empty()){
            return -1;
        }
        else{
            return st.top();
        }
    }
    int getMin(){
        // return the minimum element from the minStack (top value)
        if(minStack.empty()){
            return -1;
        }
        else{
            return minStack.top();
        }
    }


};
int main(){
    stack2 s;
    s.push(5);
    s.push(3);
    s.push(8);
    s.push(2);
    s.push(4);
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    cout << " minimum number of stack is : " << s.getMin() << endl;
    
    return 0;
}