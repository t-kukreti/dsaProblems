#include<iostream>
#include<vector>
using namespace std;
int second_largest_element(vector<int> nums){
    int largest = nums[0], second_largest = -1;
    for(int i=0; i<nums.size(); i++){
        if(nums[i] > largest){
            second_largest = largest;
            largest = nums[i];
        }
    }
    return second_largest;

}
int main(){
vector<int> nums = {1,5,8,5,6};
cout << "Second largest element: " << second_largest_element(nums) << endl;


}