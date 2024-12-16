#include<iostream>
#include<math.h>
using namespace std;
// Complete this and generalise it form any equation and make a string of multiple values and solve for that . 
void derivative(int x, int n){
    int ans = n* pow(x,n-1);
    cout<<ans;
}
int main(){
    //   f(x) = x^5 + 64 ;
    int n , x = 2;
    cout<< " Enter power of x ";
    cin>>n;
    derivative(x,n);
    return 0;
}