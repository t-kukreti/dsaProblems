#include<iostream>
#include<vector>
#include<map>
#include<cmath>
using namespace std;
void print(vector<int> v){
    for(int i = 0 ; i<v.size() ; i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

vector<int> topKFrequent(vector<int> &nums , int k){

   map<int,int> freqMap;
    for(int i = 0 ; i<nums.size() ; i++){
        int element = nums[i];
        freqMap[element]++;
    }
    
    vector<int>ans;
    
return ans;
}


int main(){
    vector<int> nums = {1,2,2};
    int k = 1;
    vector<int> ans = topKFrequent(nums,k);
    print(ans);

    
    return 0;
}