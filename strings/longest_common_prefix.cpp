#include<iostream>
#include<string>
#include<vector>
using namespace std;

string longestCommonPrefix(vector<string> &strs){
    string common_prefix = strs[0];


    for(int i = 1; i < strs.size(); i++){
        int min_len = min(common_prefix.length(), strs[i].length());
        int j; 
        for(j = 0; j < min_len; j++){
            if(common_prefix[j] != strs[i][j]) break;
        }
        // one string ended
        common_prefix = common_prefix.substr(0,j);       
    }
    return common_prefix;
}
int main(){
    vector<string> strs = {"flower", "flow", "flight"};
    cout << longestCommonPrefix(strs) << endl;

    return 0;
}