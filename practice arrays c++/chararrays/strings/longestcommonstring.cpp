#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

// proper code needed 

string longestcommonstr(vector<string> &strs){
    int minstr = 201;
    for(int i = 0 ; i < strs.size() ; i++){
        int a = (strs[i].size());
        minstr = min(a , minstr);
    }
    string ans = "";
   
return ans;

}

int main(){
 vector<string> strs = {"flower","flow","flight"};
 cout<< "The answer is " <<longestcommonstr(strs);


    return 0;
}