#include<iostream>
using namespace std;
bool PossbileSolution(int mid, int maxSum){
    int maxVal = mid;
    int adjacentValues = mid-1;

    if( (2*adjacentValues)+ maxVal <= maxSum){
        return true;               
    }
    return false;
}
int maxValue(int n, int index, int maxSum) {
    int s=0,e=maxSum,mid,ans;
    mid = s+(e-s)/2;

    while(s<=e){
        if(PossbileSolution(mid,maxSum)){
            ans = mid;
            s = mid+1;
        }
        else{
            e = mid-1;
        }
         mid = s+(e-s)/2;
    }

return ans;
}

int main(){
    int n = 3, index = 2, maxSum = 18;
    int ans = maxValue(n,index,maxSum);
    cout<< ans << endl;

    return 0;
}