#include<iostream>
#include<deque>
using namespace std;

int main(){
    deque<int> d;
    d.push_front(12);
    d.push_back(14);
    d.pop_front();
    d.pop_back();
  
    if(d.empty()){
        cout << " queue is empty " << endl;
    }
    else{
        cout << d.front() << endl;
        cout << d.back() << endl;
    }
    return 0;
}