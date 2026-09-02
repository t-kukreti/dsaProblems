#include<iostream>
#include<vector>
#include<string>
using namespace std;

void solve(vector<string> &ans, string &curr, vector<string> &mapping, string &digits, int index) {
    if(index == digits.length()){
        ans.push_back(curr);
        return ;
    }

    // get the choices. 
    string choices = mapping[digits[index] - '2'];

    for(int i = 0; i < choices.length(); i++){
        curr.push_back(choices[i]); // selects each letter of the current digit's choices one by one.
        solve(ans, curr, mapping, digits, index+1); // iterates to digits[1] till all digits are taken
        curr.pop_back(); // removes last choice and move to next i, helping us in taking choice[1]
    }
};


vector<string> letterCombinations(string digits) {
    vector<string> ans;
    string curr;
    
    vector<string> mapping = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    solve(ans, curr, mapping, digits, 0);
    return ans;
}

void print_vector(vector<string> &v){
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
}



int main() {
    string digits = "234";
    vector<string> ans = letterCombinations(digits);
    print_vector(ans);

    return 0;
}