#include<iostream>
#include<stack>
using namespace std;

string  reverse_string(stack<char> s){
    string ans = "";
    while(!s.empty()){
        char ch = s.top();
        ans.push_back(ch);
        s.pop();

    }
return ans;

}
int main(){
    string str = "tarun";
    stack<char> st;
    for(int i = 0 ; i<str.length(); i++){
        st.push(str[i]);
    }
    cout<<"Befor reversing: "<<str<<endl;
    cout<<"After reversing: " << reverse_string(st);
    return 0;
}