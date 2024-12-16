#include<iostream>
#include<string>
using namespace std;

int get_length_of_last_word(string s){
    int count = -1;
    bool letterCame = false;
    for(int i = s.size() -1; i >= 0; i--){
        // terminating condition
        if((s[i] == ' ' && letterCame)){
            break;
        }
        else if((s[i] != ' ' && !letterCame)){
            letterCame = true;
            count ++;
        }
        else if(s[i] != ' ' && letterCame){
            count ++;
        }
    }
    return count + 1;
}

int main(){
    string st = "hello";
    cout << get_length_of_last_word(st);
    return 0;
}