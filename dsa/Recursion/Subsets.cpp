#include<iostream>
#include<vector>
using namespace std;
// void print(vector<int>v){
//     for(int i = 0; i<v.size();i++){
//         for(int j = 0 ;j<v.size();j++){
//             cout<<v[i]v[j]<<" ";
//         }
//     }
//     cout<<endl;
// }
void solve(vector<int>nums,vector<int>output,int index , vector<vector<int>>&ans){
    // base case
    if(index >= nums.size()){
        ans.push_back(output);
        cout<<"Returned " << endl;
        return ;
    }
    // exclude call
    cout<<"excluding call" << endl;
    solve(nums,output,index+1,ans);
    // include call
    int element = nums[index];
    output.push_back(element);
    cout<<"Include call " << endl;
    solve(nums,output,index+1,ans);
}
vector<vector<int>>subset(vector<int>nums){
    cout<<"HAAN BHAI HOGYA HU EXECUTE " << endl;
    vector<vector<int>> ans;
    int index = 0;
    vector<int>output;
    solve(nums,output,index,ans);
    return ans;
}
int main(){
    vector<int>nums={1,2,3};
    subset(nums);
    
    return 0;
}