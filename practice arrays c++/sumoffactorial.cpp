#include<iostream>
using namespace std;
int fact(int n){
    if(n<=1){
        return 1;
    }
    return n*fact(n-1);
}
int sumoffact (int n){
 int sum = 0;
    for(int i=1;i<=n;i++){
        sum = fact(i) + sum;
        cout<<"sum is " << sum << " when fact(" <<i<< " ) is " << fact(i)<<endl; 
    }
    return sum; 

}
int main(){
    int n;
    cin>>n;
    // int sum = 0;
    cout<<fact(n);
    cout<<sumoffact(n);
    return 0;
}