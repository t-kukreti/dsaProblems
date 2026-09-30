#include<iostream>
#include<vector>

using namespace std;
void printVector(vector<int> &v){
    for(int i=0; i<v.size(); i++){
        cout << v[i];
    }
    cout << endl;
}
// still O(n) space.
vector<int> rearrange(vector<int> &nums){
    vector<int> ans(nums.size());
    int pos = 0, neg = 1;

    for(int i=0; i<nums.size(); i++){
        if(nums[i] >= 0){
            ans[pos] = nums[i];
            pos += 2;
        }
        else{
            ans[neg] = nums[i];
            neg += 2;
        }
    }
    return ans;
}
// brute force
vector<int> rearrangeArray(vector<int> &nums){

    vector<int> positiveNumbers;
    vector<int> negativeNumbers;
    vector<int> ans; 

    for(int i=0; i<nums.size(); i++){
        if(nums[i] >= 0){
            positiveNumbers.push_back(nums[i]);
        }
        else{
            negativeNumbers.push_back(nums[i]);
        }
    }

    for(int i=0; i<positiveNumbers.size(); i++){
        ans.push_back(positiveNumbers[i]);
        ans.push_back(negativeNumbers[i]);
    }
    return ans;
}

int main(){
    vector<int> nums = {3, 1, -2, -5, 2, -4};
    vector<int> res = rearrange(nums);
    printVector(res);
    return 0;
}