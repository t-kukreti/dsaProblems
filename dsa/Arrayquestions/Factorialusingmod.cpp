#include<iostream>
#include<math.h>
using namespace std;
int factorial(int num , int m){
    int ans = 1;
    while(num>0){
        ans = (num * ans)%m;
        num --;
    }
    return ans;

}
int main(){
    int num;
    cout<<"Enter a number " <<endl;
    cin>>num;
    int m = pow(10,9) + 7;
    cout<<m<<endl;
    cout<<"Factorial of " << num << " is " << factorial(num , m ) <<endl;
    return 0;
}