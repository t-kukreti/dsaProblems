#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int subarraySum(vector<int> &nums, int k){
    vector<int> sums = {0};
    // get each cumulative sum 
    int sum = 0;
    for(int i=0; i<nums.size(); i++){
        sum += nums[i];
        sums.push_back(sum);
    }
    unordered_map<int, int> sum_seen;
    sum_seen[0] = 1; 
    int count = 0;
    for(int i=1; i<sums.size(); i++){
        // get current sum - k
        int currentSum = sums[i]; 
        int needed = currentSum - k;
        if(sum_seen.find(needed) != sum_seen.end()){
            count += sum_seen[needed];
        }
        sum_seen[currentSum] ++;
    }
    return count;
}
int main(){
    vector<int> nums = {1,2,3};
    cout << subarraySum(nums, 3) << endl;
    return 0;

}