#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void printAns(vector<vector<int>> &v){
    for(int i=0; i<v.size(); i++){
        for(int j=0; j<v[i].size(); j++){
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void solve(vector<vector<int>> &ans, vector<int> &nums, vector<int> &curr, int index){
    // push the curr state
    ans.push_back(curr);

    // start the looop
    for(int i = index; i < nums.size(); i++){
        // skip the duplicate branch at same recursion level
        if( (i > index) && (nums[i] == nums[i-1]) ) continue;
        curr.push_back(nums[i]);

        // recurse
        solve(ans, nums, curr, i+1);

        // undo
        curr.pop_back();
    }

}

vector<vector<int>> subsetsWithDup(vector<int> &nums){
    vector<vector<int>> ans; 
    vector<int> curr;
    sort(nums.begin(), nums.end());
    
    solve(ans, nums, curr, 0);
    return ans;
}


int main(){
    vector<int> nums = {1,2,3};
    vector<vector<int>> res = subsetsWithDup(nums);

    printAns(res);


    return 0;
}