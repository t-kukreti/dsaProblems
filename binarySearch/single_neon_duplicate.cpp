#include<iostream>
#include<vector>
using namespace std;

int singleNeonDuplicate(vector<int> &nums){
    int left = 0, right = nums.size() - 1;

    while(left < right){
        int mid = left + (right - left) / 2;
        if( (nums[mid] != nums[mid+1]) && (nums[mid] != nums[mid-1])) return nums[mid];

        else if(nums[mid] == nums[mid+1]){
            if((mid & 1) == 0){
                left = mid + 1 + 1;
            }
            else{
                right = mid - 1;
            }
        }
        else{
            if( ((mid-1) & 1) == 0){
                left = mid + 1;
            }
            else{
                right = mid - 1 - 1;
            }

        }
    }
    if(left == right) return nums[left];
    return -1;
}
int main(){
vector<int> nums = {1,1,2,2,3,4,4};
cout << singleNeonDuplicate(nums) << endl;
    return 0;
}