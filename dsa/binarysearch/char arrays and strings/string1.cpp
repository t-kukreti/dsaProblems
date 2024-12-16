#include<iostream>
#include<string>
using namespace std;
string replacestring(string &s ){
    string temp = ""; // Try to do it without making extra string (taking extra space) 
    for(int i = 0 ;i < s.length() ; i ++){
        if(s[i] == ' ' ){
            temp.push_back('@');
            temp.push_back('4');
            temp.push_back('0');
        }
        else{
                temp.push_back(s[i]);
        }
    }
    return temp;
}
int main(){
    string s;
    cout<<"Enter your string " <<endl;
    getline(cin,s);
    cout<<"Your string after replacement " <<endl;
   cout<< replacestring(s);
     return 0;
}