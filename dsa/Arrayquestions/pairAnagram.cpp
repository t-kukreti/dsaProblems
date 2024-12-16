#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<algorithm>
using namespace std;
// optimize it.
void print(vector<string>s){
    for(int i = 0 ; i<s.size() ; i++){
        cout<<s[i]<<" ";
    }
    cout<<endl;
}
void printvector(vector<vector<string>> v){
    for(int i = 0 ; i<v.size() ; i++){
        for(int j = 0 ; j<v.size() ; j++){
            cout<<v[i][j]<<" ";
        }
    }
    cout<<endl;
}
// bool areAnagram(string s1 , string s2){
//     if(s1.length() != s2.length() ){
//         return false;
//     }

//     sort(s1.begin(), s1.end());
//     sort(s2.begin(), s2.end());
//     for(int i = 0 ; i<s1.length() ; i++){
//         if(s1[i] != s2[i]){
//             return false;
//         }
//     }
//     return true;


// }

// vector<vector<string>> groupAnagrams(vector<string> &strs){
//     vector<string> output;
//     vector<vector<string>> ans;
//     map<int,bool> visited;
//     int i = 0 , j = 0;

//     while( i<strs.size() ){
//         // if its visited then move forward , else put the element and therir anagram
//         if(visited[i]){
//             i++;
//         }
//         else{
//             output.push_back(strs[i]);
//             visited[i] = 1;
//             for( j = i+1 ; j<strs.size() ; j++){
//                 if(areAnagram(strs[i],strs[j])){
//                     output.push_back(strs[j]);
//                     visited[j] = 1;
//                 }
         
//             }
//             // push it into ans
//             ans.push_back(output);

//             // empty the output string 
//             output.clear();
//         i++;
//         }
//     }



// return ans;

// }

// optimized version
vector<vector<string>> group_anagrams(vector<string>&strs){
    unordered_map<string, vector<string>> anagrams;

    // iterate over vector string and sort every str 
    for(int i=0 ; i<strs.size() ; i++){
        string sortedStr = strs[i];
        // sort the string
        sort(sortedStr.begin() , sortedStr.end());
        // push string from original str to sorted str as key
        anagrams[sortedStr].push_back(strs[i]);
    }
    
    vector<vector<string>> ans;
    // iterate and get the values associated with keys and push it to ans
    for( unordered_map<string, vector<string>> :: iterator it = anagrams.begin() ; it != anagrams.end() ; it++){
        ans.push_back(it->second);
    }
      printvector(ans);
    return ans;
}
int main(){
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    group_anagrams(strs);
    // it can be optimized more watch neetcode solution 
 

    return 0;
}