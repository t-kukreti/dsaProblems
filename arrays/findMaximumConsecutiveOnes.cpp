#include<iostream>
#include<vector>

using namespace std;

    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0, max_cons_one = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 1) count ++;
            if(nums[i] == 0) count = 0;

            if(count > max_cons_one) max_cons_one = count;
        }
        return max_cons_one;
    }
int main(){
    vector<int> nums = {1,1,0,1,1,1};
    cout << findMaxConsecutiveOnes(nums) << endl;
    return 0;
}