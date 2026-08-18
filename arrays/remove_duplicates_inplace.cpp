#include<iostream>
#include<vector>
using namespace std;
void print_vector(vector<int> n){
    for(int i=0; i<n.size(); i++){
        cout << n[i] << " ";
    }
    cout << endl;
}

int remove_duplicates_from_sorted_arr(vector<int>&nums){
    int j = 0,temp = 0;
    for(int i=1; i<nums.size(); i++){
        if(nums[j] != nums[i]){
            temp ++;
            nums[temp] = nums[i];
            j = i;
        }
    }
    for(int i = nums.size()-1; i> temp; i--){
        nums.pop_back();
    }

    print_vector(nums);
    return nums.size();
}
int main(){
    vector<int> nums = {1,2,2,2,3};
    cout << remove_duplicates_from_sorted_arr(nums)<<endl;


    return 0;
}