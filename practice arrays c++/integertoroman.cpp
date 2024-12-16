#include<iostream>
#include<map>
using namespace std;
string inttoroman(int num){
    map<int,char> mp ;
    

}
int main(){
    int num ;
    cout<<"Enter a number " ;
     cin>> num ; 
    cout<<"This is your entered number " << num <<endl;
    string ans = inttoroman(num);
    cout<< "Roman number of " << num << " is : " << ans <<endl;

    
    return 0;
}