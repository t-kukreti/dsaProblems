#include<iostream>
using namespace std;
void printarr(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
// ascending order
void selectionsort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int minindex=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minindex]){
                minindex=j;
            }
        }
        swap(arr[minindex],arr[i]);
    }
}
// descending order
void selectionsort1(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int maxindex=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]>arr[maxindex]){
                maxindex=j;
            }
        }
        swap(arr[maxindex],arr[i]);
    }
}
int main(){
    int arr[]={64,25,12,22,11};
      int n=sizeof(arr)/sizeof(arr[0]);
    printarr(arr,n);
  
    selectionsort(arr,n);
    printarr(arr,n);
    return 0;
}
// SPACE COMPLEXITY -> O(1)  as we are using only variables and not taking any other space
// TIME COMPLEXITY -> O(n^2) as we are using two nested for loops 
// USE  CASE -> when array/vector/list size is small           
// stable or unstable homework question