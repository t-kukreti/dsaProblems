#include<iostream>
#include<vector>
using namespace std;
// Code studio Subsequences of a string 
// Both questions can be done by bits manipulation , try it out 
void solve(string str,string output,int index , vector<string>&ans){
    if(index>=str.length()){
        if(output.length() > 0){
        ans.push_back(output);
        }
        return ;
    }
    // exclude call
    solve(str,output,index+1,ans);
    // include call
    char element = str[index];
    output.push_back(element);
    solve(str,output,index+1,ans);

}

vector<string> subsequences(string str){
    string output="";
    vector<string>ans;
    int index =0;
    solve(str,output,index,ans);
    return ans;


}

int main(){
    string str = "abc";
    subsequences(str);

    return 0;
}