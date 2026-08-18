#include<iostream>
#include<string>
#include<set>
#include<vector>

#include<unordered_map>
using namespace std;

string check_duplicates(string s, int len){
    const long long MOD = 1e9 + 7;
    unordered_map<long long, vector<int>> seen;
    // compute the first hash
    long long hash = 0;
    long long power = 1; 

    if(len > s.length()) return "";

    for(int i = 0; i < len-1; i++){
        power = (power * 31) % MOD;
    }
    

    for(int i = 0; i < len; i++){
        int value = s[i] - 'a' + 1;
        hash = (hash * 31 + value) % MOD; 
    }

    seen[hash].push_back(0);
    // now roll 
    for(int i = len; i < s.length(); i++){
        int start = i - len + 1;
        int remove = s[i - len] - 'a' + 1;
        int add = s[i] - 'a' + 1;
        hash = (hash - (remove * power) % MOD + MOD) % MOD;
        hash = (hash * 31 + add) % MOD;
        if(seen.find(hash) != seen.end()){
                for(int pos : seen[hash]){
        if(s.compare(pos, len, s, start, len) == 0){
            return s.substr(start, len);
        }
    }
        }
        seen[hash].push_back(start);
    }
    return "";
}
string longestDupSubstring(string s){
    int left = 1, right = s.length() - 1;
    string ans = "";

    while(left <= right){
        int mid = left + (right - left) / 2;
        string duplicate = check_duplicates(s,mid);

        if(duplicate != ""){
            ans = duplicate;
            left = mid+1;
        }
        else{
            right = mid - 1;
        }
    }
    return ans;
}
int main(){
    string s = "banana";
    cout << longestDupSubstring(s) << endl;

    return 0;
}