#include<iostream>
#include<vector>
using namespace std;

void printVector(vector<int> &v){
    for(int i=0; i<v.size(); i++){
        cout << v[i]; 
    }
    cout << endl;
}
// to swap elements 
void reverse(vector<int> &v, int left, int right){
    while(left <= right){
        swap(v[left], v[right]);
        left ++, right --;
    }
}

void nextPermutation(vector<int> &nums){
// find the element that breaks the non-descending order [1,2,4,3] => 2 as 3,4 
    int pivotIndex = -1;
    for(int end = nums.size()-1; end >= 0; end --){
        if((end-1) >= 0 && nums[end-1] < nums[end]){
            pivotIndex = end-1;
            break;
        }
    }
    if(pivotIndex < 0){
        // the whole nums is in a non descending order
        reverse(nums,0,nums.size()-1);
    }
    else{
        // find the element to swap with it
        int j = 0;
        for(j=nums.size()-1; j>pivotIndex; j--){
            if(nums[pivotIndex] < nums[j]){
                break;
            }
        }
        swap(nums[j], nums[pivotIndex]);
        reverse(nums, pivotIndex+1, nums.size()-1);
    }

}

int main(){

    vector<int> nums = {1,2,3};
    nextPermutation(nums);
    printVector(nums);

    return 0;
}