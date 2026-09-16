#include<iostream>
#include<vector>

using namespace std;

   int singleNumber2(vector<int>& nums) {
        int ans=0;
        int count[32] = {0};
        for(int i=0; i<nums.size(); i++){
            for(int j=0; j<32; j++){
                // get bit j from nums[i]
                if((nums[i] >> j) & 1){
                    count[j] ++;
                }

            }
        }
        for(int i=0; i<32; i++){
            count[i] %= 3;
            if(count[i] == 1){
                ans = ans | (1 << i);
            }
        }
        return ans;
    }


int main(){
    vector<int> nums = {2,2,3,2};
    cout << singleNumber2(nums) << endl;
    return 0;
}