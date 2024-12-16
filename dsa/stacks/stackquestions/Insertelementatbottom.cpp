#include<iostream>
#include<stack>

using namespace std;
stack<int> insert_element_at_bottom(stack<int>&myStack , int x){
    // base case
    if(myStack.empty()){  
        myStack.push(x);
        cout<<"Element at the lowermost position is : " << myStack.top() << endl;
        return myStack;
    }
    // storing element that will be popped
    int num = myStack.top();
    myStack.pop();
    // Recursive calls
    insert_element_at_bottom(myStack,x);
    // pushing popped elements back inside after putting x 
    myStack.push(num);

    return myStack;

}

int main(){
    stack<int> st;
    st.push(1);
    cout<<"Element at lowermost position in the stack (before inserting ) is : "
    << st.top()<<endl;
    st.push(2);
    st.push(3);
    st.push(4);
    int x = 5;
    insert_element_at_bottom(st,x);    
    return 0;
}