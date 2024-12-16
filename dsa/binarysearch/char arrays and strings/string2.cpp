#include<iostream>
using namespace std;
string removeoccurence(string &str , string part){

    while(str.length()!=0 && str.find(part)<str.length()){
        str.erase(str.find(part) , part.length());
    }
    return str;
}

bool checkequal(int a[26] , int b[26]){
    for(int i = 0;i < 26 ;i++){
        if(a[i] != b[i]){
            return 0;
        }
    }
        return 1;
}
bool checkpermutation(string s1 , string s2){

    int count1[26] = {0};
    for(int i = 0 ; i< s1.length(); i ++ ){
            int index =  s1[i] - 'a';  
            count1[index]++;
    }
    // traverse s2 in window of s1 length and compare
    int i = 0 ;
    int window_size = s1.length();
     int count2[26] = {0};
    // running for first window
    while(i<window_size && i<s2.length()){
        int index = s2[i] - 'a';
        count2[index]++;
        i ++;
    }

    if (checkequal(count1,count2)){
        return 1;
    }

    // aage process kro
    while(i<s2.length()){
        char newchar = s2[i] ;
         int index = newchar  - 'a' ;
            count2[index]++;
        char oldchar = s2[i-window_size];
         index = oldchar - 'a';
        count2[index]--;
        i++;
        if(checkequal(count1,count2)){
            return 1;
        }

    }
    return 0;


}
int main(){
    /* 
    string str = "daabcbaabcbc";
    string part = "abc";
    cout<<removeoccurence(str,part)<<endl; 
    */

   // PERMUTATION IN STRING
    string s1 = "ab";
    string s2 = "eidbaooo";
    cout<<checkpermutation(s1,s2)<<endl;
    return 0;
}