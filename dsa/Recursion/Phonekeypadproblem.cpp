#include<iostream>
#include<vector>
using namespace std;
void printvector(vector<string>s){
    for(int i = 0 ; i<s.size(); i++){
        cout<<s[i]<<" ";
    }
    cout<<endl;
}
void solve(string digits , string output, int index , vector<string>&ans , string map[]){
    if(index>=digits.length()){
        ans.push_back(output);
        return ;
    }
    int number = digits[index] - '0';
    string value = map[number];
    for(int i = 0 ; i<value.length() ; i++){
        output.push_back(value[i]);
        solve(digits,output,index+1,ans,map);
        output.pop_back();
    }
}
vector<string> lettercombinations(string digits){
    vector<string>ans;
    if(digits.length() == 0 ){
        return ans;
    }
    string output;
    int index = 0;
    string map[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    solve(digits,output,index,ans,map);
    return ans;
}

int main(){
    string digits;
    cout<<"Enter a number (0-9) " << endl;
    cin>>digits;
    printvector(lettercombinations(digits)); 

    return 0;
}