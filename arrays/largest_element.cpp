#include<iostream>
#include<vector>
using namespace std;
int largest_element(vector<int> nums){
    int largest = nums[0];
    for(int i=0; i<nums.size(); i++){
        if(nums[i] > largest){
            largest = nums[i];
        }
    }
    return largest;
}
int main(){
vector<int> nums = {1,5,8,5,6};
cout << "largest element: " << largest_element(nums) << endl;


}