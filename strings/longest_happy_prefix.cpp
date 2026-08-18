
#include<iostream>
#include<string>
using namespace std;

string longestPrefix(string s){
    string ans = "";

    int lps[s.length()] = {0}, len = 0, i = 1;
    while(i < s.length()){

        if(s[i] == s[len]){
            len ++;
            lps[i] = len;
        }
        else{
            while(len != 0){
                if(s[len] == s[i]){
                    len++;
                    lps[i] = len;
                    break;
                }
                else{
                    len = lps[len - 1];
                }
            }
            if(len == 0){
                if(s[i] == s[len]){
                    len++;
                }
                lps[i] = len;     
            }
        }
        i++;
    }
    ans = s.substr(0,lps[s.length()-1]);
    return ans;
}

int main(){
    string s = "abababc";
    cout << longestPrefix(s) << endl;
    return 0;
}