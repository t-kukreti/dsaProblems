#include<iostream>
#include<stack>
#include<queue>
using namespace std;
// recurive solution

queue<int> reverse(queue<int> q){
    // when only one element is left 
    if (q.size() <= 1){
        return q;
    }
    
    int element = q.front();
    q.pop();
    // recursive relation
    queue<int> ans = reverse(q);
    // push after reaching last element
    ans.push(element);

    return ans; 
}

// iteratively using a stack
queue<int> reverseQueue(queue<int> q){
    stack<int> st;
    queue<int> ans;
    // empty q and put it in stack
    while (!q.empty()){
        int element = q.front();
        q.pop();
        st.push(element);
    }
    // empty stack push it in answer lifo order so it will be reversed
    while(!st.empty()){
        int element = st.top();
        st.pop();
        ans.push(element);
    }
    return ans;
}

int main(){
    queue<int> q;
    for(int i = 1; i<= 5; i++){
        q.push(i);
    }
    cout << " before reversing " << endl;
    cout << " front : " << q.front()
    << " back : " << q.back() << endl;

    queue<int> ans = reverse(q);
    cout << " after reversing " << endl;
    cout << " front : " << ans.front()
    << " back : " << ans.back() << endl;

    return 0;
    
}