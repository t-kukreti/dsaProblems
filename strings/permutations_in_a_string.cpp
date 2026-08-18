#include<iostream>
#include<string>
using namespace std;

bool match_arr(int arr1[], int arr2[]){
    for(int i = 0; i < 26; i++){
        if(arr1[i] != arr2[i]) return false;
    }
    return true;
}



bool checkInclusion(string s1, string s2){

    if(s1.length() > s2.length()) return false;

    // get the frequency of chars in s1
    int freq_of_chars_s1[26] = {0};
    for(int i=0; i<s1.length(); i++){
        freq_of_chars_s1[s1[i] - 'a'] ++;
    }

    int freq_of_chars_s2[26] = {0};
    
    // build first window
    int start = 0, end = s1.length()-1;
    for(int i = 0; i <= end; i++){
        freq_of_chars_s2[s2[i] - 'a']++;
    }

    if(match_arr(freq_of_chars_s1,freq_of_chars_s2)) return true;

    while(end < s2.length() - 1){
        freq_of_chars_s2[s2[start] - 'a'] --;
        start ++, end++;
        freq_of_chars_s2[s2[end] - 'a'] ++;
        if(match_arr(freq_of_chars_s1, freq_of_chars_s2)) return true;
    }
    return false;
}

int main(){
string s1 = "ab";
string s2 = "eidbaooo";

cout << checkInclusion(s1,s2) << endl;

    return 0;
}