#include<iostream>
#include<stack>
using namespace std;

int main(){ 
    stack<int> s;
    
     for(int i = 1 ; i<=10 ; i++){
        s.push(i);
        cout<<s.top()<<endl;
     }

cout<<"the size of stack is " << s.size () << endl; // number of elements
cout<<"is stack empty ? " << s.empty () << endl; // returns boolean values
 s.pop();
cout<<"after popping " << s.top () << endl;

// using swap
    stack<int> s2;
    s2.push(1);
    s.swap(s2);
cout<<"the last element is " << s.top () << endl; 
    





    
    return 0;
}