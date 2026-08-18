#include<iostream>
#include<string>
#include<climits>
using namespace std;

string minWindow(string s, string t){
    string ans = "";
    int min_len = INT_MAX;
    // freq map of t
    int freq_t[128] = {0};
    for(int i = 0; i < t.length(); i++){
        freq_t[t[i]] ++;
    }

    int freq_window[128] = {0};
    int left = 0, right = 0, have = 0, need = t.length(), window_length = -1, start = 0;

    while(right < s.length()){
        freq_window[s[right]]++;

        if(freq_window[s[right]] <= freq_t[s[right]]){
            have ++;
        }

        // current window is valid
        while(have == need){
            window_length = right - left + 1;
            if(window_length < min_len){
                min_len = window_length;
                start = left;
            } 

            if(freq_window[s[left]] <= freq_t[s[left]]){
                have --;
            }
            
            freq_window[s[left]]--;

            left ++;

        }
        right++;
    }
    if(min_len == INT_MAX) return "";
    return s.substr(start,min_len);

}
int main(){
    string s = "ADOBECODEBANC";
    string t = "ABC";
    cout << minWindow(s,t) << endl;

    return 0;
}