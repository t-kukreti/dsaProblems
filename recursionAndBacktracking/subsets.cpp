#include<iostream>
#include<vector>
using namespace std;

void solve(vector<vector<int>> &ans, vector<int> &nums, vector<int> &current, int index){
    if(index == nums.size()){
        ans.push_back(current);
        return ;
    }
    // store it in ans
    current.push_back(nums[index]);
    solve(ans, nums, current, (index+1));

    // pop 
    current.pop_back();
    // skip
    solve(ans, nums, current, (index+1));
    
}
vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> current;
    solve(ans, nums, current, 0 );

    return ans;
        
}
void printVector(vector<vector<int>> v){
    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < v[i].size(); j++){
            cout <<v[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

}

int main(){

    vector<int> nums = {1,2,3};

    vector<vector<int>> res = subsets(nums);
    printVector(res);

    return 0;
}