#include<iostream>
#include<vector>
using namespace std;
void print(vector<string> v){
    for(int i = 0 ; i<v.size() ; i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
void solve(string s, int index, vector<string> &ans){
    if(index>=s.length()){
        ans.push_back(s);
        return ;
    }

    for(int j = index ; j<s.length() ; j++){
        swap(s[index],s[j]);
        solve(s,index+1,ans);
        // Backtrack
        swap(s[index],s[j]);
        // As the changes are happening in the original string we want to make sure that when it goes back to original string it should remain "abc" not anyother form like "bac" , so to neutralize the effect we swap it after function call too ! 
    }
}
vector<string> permutationsofastring(string s){
    vector<string>ans;
    int index = 0;
    solve(s,index,ans);
    return ans;
}
int main(){
    string str="abc";
   print(permutationsofastring(str));

    return 0;
}