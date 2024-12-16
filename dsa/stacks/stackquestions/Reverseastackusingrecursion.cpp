#include<iostream>
#include<stack>
using namespace std;
void insertatbottom(stack<int>& st , int num){
    if(st.empty()){
        st.push(num);
        return;
    }
    int x = st.top();
    st.pop();

    insertatbottom(st,num);
    st.push(x);


}
void reverse_stack(stack<int> &st){
    // base case
    if(st.empty()){
        return ;
    }
    int num = st.top();
    st.pop();

    reverse_stack(st);

    insertatbottom(st , num);


}

int main(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3); 
    cout<<"Before reversing : " <<st.top() << endl;
    reverse_stack(st);
    cout<<"After reversing : " <<st.top() << endl;

    
    return 0;
}