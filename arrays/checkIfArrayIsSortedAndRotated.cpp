#include<iostream>
#include<vector>
#include<climits>

using namespace std;

bool check(vector<int> &nums){
    int breakCount = 0;
    // in a sorted and rotated array, break can only happen once.
    for(int i=0; i<nums.size(); i++){
       if(nums[i] > nums[(i+1) % nums.size()]) breakCount ++; 
    }

    return breakCount <= 1;
}
int main(){
    vector<int> nums = {2,3,4,1,1};
    cout << check(nums) << endl;

    return 0;
}