#include<iostream>
#include<vector>
using namespace std;
int lastOccurence(vector<int> &nums, int element){
    for(int i=0; i<nums.size(); i++){
        if(nums[i] != element){
            return i - 1;
        }
    }
    return -1;
}
bool isMonotonic(vector<int> &nums){
    int len = nums.size()-1;
    if(len == 0 || len == 1){
        return true;
    }
    int firstElementLastOccurence = lastOccurence(nums, nums[0]);
    if(firstElementLastOccurence == -1){
        return true;
    }
    else if(nums[firstElementLastOccurence] < nums[firstElementLastOccurence + 1]){
        for(int i=0; i<len; i++){
            if(nums[i] > nums[i+1]){
                return false;
            }
        }
    }
    else if(nums[firstElementLastOccurence] > nums[firstElementLastOccurence + 1]){
        for(int i=0; i<len; i++){
            if(nums[i] < nums[i+1]){
                return false;
            }
        }
    }
    return true;
}


// one more solution 
bool isMonotonicArray(vector<int> &v){
    int len = v.size()-1;
    bool isIncreasing = false, isDecreasing = false;
    for(int i=0; i<len; i++){
        if(v[i] < v[i+1]){
            isIncreasing = true;
        }
        else if(v[i] > v[i+1]){
            isDecreasing = true;
        }
    }
    return (isIncreasing && isDecreasing) ? false : true;

}
int main(){
    vector<int> nums = {1,1,1};
    bool ans = isMonotonicArray(nums);
    cout<< ans <<endl;
    
    return 0;
}