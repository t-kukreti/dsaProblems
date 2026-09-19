#include<iostream>
#include<vector>

using namespace std;


// Lets not throw away the exisiting sum
int longestSubArr(vector<int> nums, int k){
    int left= 0, right= 0, sum= 0, maxLen= 0, len= -1;
    while(right < nums.size()){
        sum += nums[right];
        while(sum > k){
            sum = sum - nums[left];
            left ++;
        }
        if(sum == k){
            len = right - left + 1;
            if(maxLen == 0) maxLen = len;
            if(len > maxLen) maxLen = len;
        }
        right ++;
    } 
    return maxLen;
}
/*
int longestSubArrWithSumKPos(vector<int> nums, int k){
    int sum= 0, len= -1, maxLen= 0, nextPos = 0;
    for(int i=0; nextPos != nums.size()-1; i++){
        
    if(i == nums.size()){
        // all elements processed, increment. 
        nextPos++, i=nextPos;
    }
    sum += nums[i];
    if(sum == k){
        len= (i-nextPos)+1;
        
        if(maxLen == 0) maxLen= len; // setting maxLen for the first  time
        else if(len > maxLen) maxLen = len; // only change if current len is bigger thn maxLen, increment.
        
        nextPos ++;
        continue;
    }
    else if(sum > k){
        nextPos++;
        i = nextPos;
        continue;
    }
    
}
return maxLen;
}
*/
int main(){
    vector<int> nums = {2,1,1,1,3};
    cout << longestSubArr(nums, 3) << endl;
    return 0;
}