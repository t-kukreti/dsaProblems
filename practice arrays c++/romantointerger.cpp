#include<iostream>
#include<map>
using namespace std;
    int romantoint(string s){
    map<char,int> mp;
    mp['I']=1; mp['V']=5; mp['X']=10; mp['L']=50; mp['C']=100; mp['D']=500; mp['M']=1000;
    int ans = 0;
    for(int i =0 ; i < s.size() ; i++){
        if(mp[s[i]]>=mp[s[i+1]]){
            ans += mp[s[i]];
        }
        else{
            ans -= mp[s[i]];
        }
    }
    return ans;
    }
int main(){
    string s;
    cout<<"Enter your roman number : " ;
    cin>>s;
    cout<<"Your roman number is : " << s <<endl;
    int sol = romantoint(s);
    cout<<"Integer is " <<sol <<endl;
    return 0;
}