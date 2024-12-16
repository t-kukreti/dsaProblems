#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int minimum_jumps_to_reach_end(vector<int> &arr){
    int n = arr.size();
    int max_jump = arr[0];
    int step = arr[0];
    int jump = 1;

    if(n==1){
        return 0;
    }
    else if(arr[0]==0){
        return -1;
    }

    for(int i = 1; i<n; i++){
        if(i==n-1){
            return jump;
        }
        max_jump = max(max_jump , i + arr[i]);
        step -- ; 
        if(step == 0){
            jump ++;
            if(i>=max_jump){
                return -1;
            }
            step = max_jump - i;
        }
    }
    return -1;    
    }




int main(){
    vector<int> arr = {2,3,1,4,4};  
 int min_jump =  minimum_jumps_to_reach_end(arr);
 cout<<"Minimum jumps required to reach end : " << min_jump <<endl;
    return 0;
}