#include<iostream>
using namespace std;
// whenever you need variables that can be accessed from more than one function use reference variable try to avoid using global scope variable 
int score = 15; // Global variable every function in your code can access this variable
// generally its a bad practice because any function can change that so you should know what you're doing

void a(int &i){
    cout<<"i in a is " << i << endl;
    cout<<"score in a " << score << endl;
    //b(i);
}

void b(int &i){
    cout<<"i in b is " << i << endl;
    cout<<"score in b " << score << endl;
}

int main(){
    int i = 5;
    a(i);
    b(i);
    cout<<"score in main " << score << endl;
    
    return 0;
}