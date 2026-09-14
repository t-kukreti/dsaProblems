#include<iostream>
#include<vector>
#include<string>

using namespace std;

void printVector(vector<string> &v){
    for(int i=0; i<v.size(); i++){
        cout << v[i] << " "; 
    }
    cout << endl;
}
void solve(vector<string> &ans, int n, string &curr, int open, int close){

    // base case
    if((open == n) && (close == n)){
        ans.push_back(curr);
        return ;
    }

    if(open < n){
        curr.push_back('(');
        solve(ans, n, curr, open+1, close);
        curr.pop_back();
    }
    if(close < open){
        curr.push_back(')');
        solve(ans, n, curr, open, close+1);
        curr.pop_back();
    }
}

vector<string> generateParenthesis(int n){
    vector<string> ans;
    string current = "";
    solve(ans, n, current, 0, 0);
    return ans;
}


int main(){
    int n = 3;
    vector<string> res = generateParenthesis(n);
    printVector(res);
    return 0;
}