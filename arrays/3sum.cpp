#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void printVector(vector<vector<int>> &v){
    for(int i=0; i<v.size(); i++){
        for(int j=0; j<v[i].size(); j++){
            cout << v[i][j] << " ";
        }
    }
    cout << endl;
}
vector<vector<int>> threeSum(vector<int> &nums){
    vector<vector<int>> ans;
    vector<int> triplet;

    // sort the nums array
    sort(nums.begin(), nums.end());
    for(int i=0; i<nums.size(); i++){

        if((i > 0) && nums[i] == nums[i-1]){
            continue;
        }

        int left = i+1, right = nums.size()-1;
        while(left < right){
            int sum = nums[i] + nums[left] + nums[right];
            if(sum == 0){

                triplet.push_back(nums[i]);
                triplet.push_back(nums[left]);
                triplet.push_back(nums[right]);

                ans.push_back(triplet);
                triplet.clear();
                left ++, right --;
                while((left < nums.size()-1 )&&(left > 0 ) && nums[left] == nums[left-1]) left ++;
                while((right > 0) && (right < nums.size()-1) && nums[right] == nums[right+1]) right --;
            }
            else if(sum < 0){
                left ++;
            }
            else{
                right --;
            }
        }
    }
    return ans;
}
int main(){
    vector<int> nums = {2,0,-2,-5,-5,-3,2,-4};
    vector<vector<int>> res = threeSum(nums);

    printVector(res);
    return 0;
}