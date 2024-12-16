#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int firstOccurence(vector<int>&v, int target){
    int count = 0;

    for(int i=0; i<v.size() ; i++){
        if(target == v[i]){
            count++;
        }
    }
    return count;
}
int lastOccurence(vector<int>&v, int target){
    int count = 0;

    for(int i=v.size()-1; i>=0 ; i--){
        if(target == v[i]){
            count++;
        }
    }
    return count;
}
int countElements(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    int lastOccurence_OfIndexFirst = firstOccurence(nums,nums[0]);
    int firstOccurence_OfIndexLast = lastOccurence(nums,nums[nums.size()-1]);

    int sol = nums.size() - (lastOccurence_OfIndexFirst + firstOccurence_OfIndexLast);
    if(sol>=0){
        return sol;
    }
    else {
        return 0;
    }
       
}

int main(){
    vector<int> nums = {-71,-71,-71,93,40};
    int ans = countElements(nums);
    cout<<ans<<endl;
    
    return 0;
}