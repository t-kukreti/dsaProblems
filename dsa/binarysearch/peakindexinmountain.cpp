#include<iostream>
using namespace std;
    int peakindex(int arr[],int n){
        int s=0;
        int e=n-1;
        int mid=s+(e-s)/2;
        while(s<e){
            if(arr[mid]<arr[mid+1]){
                s=mid+1;
            }
            else {
                e=mid;
            }
            mid = s+(e-s)/2;
        }
        return s;
    }
int main(){
    int arr[]={3,4,5,1};
    int n= sizeof(arr)/sizeof(arr[0]);
    cout<<"The index of the peak element is "<<peakindex(arr,n)<<endl;
    cout<<"The peak element is "<<arr[peakindex(arr,n)]<<endl;
    return 0;
}