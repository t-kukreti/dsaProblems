#include<iostream>
#include<stack>
using namespace std;
void sorted_insert(stack<int> &st , int num){
    if(st.empty() || (!st.empty() && st.top() < num )){
        st.push(num);
        return ;
    }

    int x = st.top();
    st.pop();
    sorted_insert(st,num);

    st.push(x);
}
void sortStack(stack<int> &stack){
    if(stack.empty()){
        return ;
    }

    int num = stack.top();
    stack.pop();
    sortStack(stack);

    sorted_insert(stack , num);


}

int main(){
    stack<int> st;
    st.push(5);    
    st.push(-2);    
    st.push(9);    
    st.push(-7);    
    st.push(3);
    cout<<"Top element before : " << st.top() << endl;
    sortStack(st);
    cout<<"Top element after : " << st.top() << endl;
    return 0;
}