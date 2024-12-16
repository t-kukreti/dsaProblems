#include<iostream>
#include<string>
using namespace std;
bool ispalindrome(int x){
    string s = to_string(x);
    int a = 0;
    int b = s.length()-1;
    while(a<=b){
        if(s[a] != s[b]){
            return false;
        }
        else{
            a++ , b--;
        }
    }
    return true;

}
int main(){
    int x;
    cout<<"Enter a number : " ; cin>>x ;
    cout<<ispalindrome(x);
    return 0;
}