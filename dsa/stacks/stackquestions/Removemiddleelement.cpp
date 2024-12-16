#include<iostream>
#include<stack>
using namespace std;
// recursive way
void solve(stack<int>&st, int count , int size){
    // basecase
    if(count == size/2){
        st.pop();
        return;
    }
    // store element
    int num = st.top();
    st.pop();
    solve(st,count+1,size);
    // put element back inside 
    st.push(num);


}
void remove(stack<int>&st){
    int count = 0;
    solve(st,count,st.size());
}

// iterative way
void remove_middle_element(stack<int> &st){
    int size = st.size();
    int mid = size/2;
    stack<int> temp;
    // store elements till you reach mid in temp stack
    for(int i = 1 ; i < (size-mid) ; i++ ){
        temp.push(st.top());
        st.pop();
    }
    // removing middle element 
    st.pop();

    while(!temp.empty()){
        st.push(temp.top());
        temp.pop();
    }
    
}
int main(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);
   cout<<"size of stack: "<< st.size() <<endl;
   remove(st);
   cout<<"size of stack: (after deletion) "<< st.size() <<endl;

    return 0;
}