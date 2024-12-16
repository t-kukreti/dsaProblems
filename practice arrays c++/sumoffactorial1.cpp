#include<iostream>
using namespace std;
int sumoffact(int n){
    int i = n-1 , sum =0;
    while(i>0){
        sum = n*i + sum;
        n-- , i--;
    }
    return sum;
}

int main(){
    int n;
    cout<<"Enter a number " << endl;
    cin>>n;
   cout<< sumoffact(n);
    return 0;
}