#include<iostream>
#include<vector>
using namespace std;

void print_vector(vector<vector<int>> &v){
    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < v[i].size(); j++){
            cout << v[i][j]; 
        }
        cout << " ";
    }
    cout << endl;
}

void solve(vector<vector<int>> &ans, vector<int> &curr, vector<int> &nums, int index, vector<bool> &used_arr){
    // base condition 
    if(index == nums.size()){
        ans.push_back(curr);
        return;
    }
    // loop
    for(int i = 0; i < nums.size(); i++){
        // if this element is take already skip it.
        if(used_arr[i]) continue;

        // push the unused element to curr
        curr.push_back(nums[i]);
        // mark that element true.
        used_arr[i] = true;

        // next choice
        solve(ans, curr, nums, index + 1, used_arr);

        // mark last element false
        used_arr[i] = false;
        // pop the last one
        curr.pop_back();

    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> curr;
    vector<bool> used_arr(nums.size(), false);

    solve(ans, curr, nums, 0, used_arr);
    return ans;

}

int main(){
    vector<int> nums = {1,2,3};
    vector<vector<int>> res = permute(nums);
    print_vector(res);
    return 0;
}