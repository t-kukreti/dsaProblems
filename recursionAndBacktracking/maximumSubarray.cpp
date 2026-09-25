#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;
// TODO: DIVIDE AND CONQUER APPROACH


// kadane's algorithm
int maxSubArray(vector<int> &nums){
    int sum = 0, maxSum = INT_MIN;

    for(int i=0; i<nums.size(); i++){

        sum += nums[i];
        maxSum = max(sum, maxSum);

        // throwing away the current sum, cause a negative accumulated sum can never contribute to max subarray.
        if(sum < 0) sum = 0;
    }
return maxSum;
}

int main(){
    vector<int> nums = {-2, 5, -1, 5};
    cout << maxSubArray(nums) << endl;
    return 0;
}