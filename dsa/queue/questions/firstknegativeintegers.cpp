#include<iostream>
#include<stack>
#include<queue>
using namespace std;
queue<int> modifyQueue(queue<int> q , int k ){
    stack<int> st;
    queue<int> ans;
    if(k > q.size() || k < 0){
        cout << "Error: check input of k " << endl;
        return ans;
    }
    // put k elements inside stack

    for(int i=0; i<k; i++){
        st.push(q.front());
        q.pop();
    }
    // now remove elements from stack and put it into answer queue
    while(!st.empty()){
        ans.push(st.top());
        st.pop();
    }
    // put remaining elements of q in ans
    while(!q.empty()){
        ans.push(q.front());
        q.pop();
    }
    return ans;
}

void printQueue(queue<int> q){
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}
int main(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    int k = 3;
    cout << " Before reversing first " << k << " elements : ";
    printQueue(q);
    cout << " After reversing first " << k << " elements : ";

    queue<int> ans = modifyQueue(q,k);
    printQueue(ans);



    return 0;
}