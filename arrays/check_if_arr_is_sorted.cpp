#include<iostream>
#include<vector>
using namespace std;


int is_sorted(vector<int> nums){
    int j = 0;
    for(int i = 0; i<nums.size()-1; i++){
        j = i+1;
        if(nums[i] > nums[j]){
            return false;
        }
    }
    return true;

}
int main(){
    vector<int> nums = {1,4,2,4};
    cout << "is sorted? " <<is_sorted(nums) << endl;




    return 0;
}