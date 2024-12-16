#include<iostream>
using namespace std;



// Binary search
/*
    why to use
    in case of 1000 size of an array a linear search would take 1000 comparison to find a element
    while in case of binary search it can do it in 10 search
    time complexity:-
      linearsearch -> O(n)  |     binarysearch -> O(log n)   (worst case complexity BIG O NOTATION)


*/




// 1. Elements should be in monotonous order (i.e. increasing or decreasing)
//  Steps to do binary search
// 1. find mid element
 // 2. compare it with your key if yes then return index , if no then decide 
 // which part to serach ahead
//  3. return the process

int binarysearch(int arr[],int n,int key){
int start = 0;
int end = n-1;
int mid =  start + (end-start)/2;                // dont use this (start+end)/2;

while(start<=end){
    if(arr[mid]==key){
        return mid;
    }
    // Go to right
    if(key>arr[mid]){
        start=mid+1;
    }
    else{ // key<arr[mid]
        end=mid-1;
    }

       mid =  start + (end-start)/2;             //mid=(start+end)/2;
   
}
 return -1;

}
int main(){
     int even[6]={2,4,6,8,12,18};
     int odd[5]={3,8,11,14,16};
     int key = 12;
    int index = binarysearch(even,6,key);
    cout<<" Index of " << key <<" is " << index << " and " << even[index]<<" is the element "<<endl;
     int key1=3;
     int index1 = binarysearch(odd,5,key1);
    cout<<" Index of " << key1 <<" is " << index1 << " and " << odd[index1]<<" is the element "<<endl;
    return 0;
}