#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void printVector(vector<vector<int>> &v){
    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < v[i].size(); j++){
            cout <<v[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

}

void solve(vector<vector<int>> &ans, vector<int> &nums, vector<int> &curr, vector<bool> &used){
    // base case 
    if(nums.size() == curr.size()){
        ans.push_back(curr);
        return ;
    }

    for(int i = 0; i < nums.size(); i++){
        // skip the sibling if at the same recursion level
        if( i > 0 && used[i-1] == false && nums[i] == nums[i-1]) continue;

        if(used[i]) continue;

        curr.push_back(nums[i]);
        used[i] = true;
        // next choice
        solve(ans, nums, curr, used);

        used[i] = false;
        curr.pop_back();
    }

}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    vector<int> curr;
    vector<bool> used(nums.size(), false);

    solve(ans, nums, curr, used);

    return ans;
}

int main(){
    vector<int> nums = {1,1,2};
    vector<vector<int>> ans = permuteUnique(nums);

    printVector(ans);

    return 0;
}