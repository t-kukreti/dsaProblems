#include<iostream>
#include<vector>
using namespace std;
// This is a brute force approach , timecomplexity is O(n)^2 , can be more efficient , just use stack 
// already done in leetcode (stack approach).
int largestRectangularArea(vector<int>&arr , int n){
     int area = -1;

    for(int i = 0 ; i<n ; i++){
        int nextIndex = -1;
        // get the next small element index for arr[i];
        int right = i+1;
        while(right < n){
            if(arr[right] < arr[i]){
                nextIndex = right;
                break;
            }
            right ++;
        }

        // get previous small element index for arr[i];
        int left = i - 1;
        int previousIndex = -1;

        while(left > 0){
            if(arr[left] < arr[i]){
                previousIndex = left;
                break;
            }  
            left --;
        }


       
        int length = arr[i];

        if(nextIndex == -1){
            nextIndex = n;
        }
        int breadth = nextIndex - previousIndex - 1;


        int newArea = length * breadth;

        area = max(area,newArea);

    }
    return area;
}

int main(){
    vector<int> heights = {1,8,6,2,5,4,8,3,7};
    cout<<"largest rectangular area is " << largestRectangularArea(heights , heights.size());

    return 0;
}