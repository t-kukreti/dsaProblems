#include<iostream>
#include<string>
using namespace std;

bool isSubsequence(string s, string t){
    // we know that string s is larger than t.

    int i = 0;
    int j = 0;
    int count = 0;

    while((i < s.size() && j < t.size())){
        if(s[i] == t[j]){
            count ++;
            i++, j++;
        }
        else{
            i++;
        }
    }

    if(count == t.size()){
        return true;
    }

    return false;
}

int main(){
    string s = "ahbgdc";
    string t = "abc";
    cout << isSubsequence(s,t) ;


    return 0;
}