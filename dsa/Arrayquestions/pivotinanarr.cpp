#include<iostream>
using namespace std;
int getpivot(int arr[],int n){
    int s=0;
    int e= n-1;
    int mid = s + (e-s)/2;
    while(s<e){
        if(arr[mid]>=arr[0]){
            s = mid+1 ;
        }
        else  {
            e= mid;
        }
        mid = s + (e-s)/2;
    }
    return s;
}
int main(){
    int arr[] = {4,5,6,7,0,1,2};
    int n= sizeof(arr)/sizeof(arr[0]);
   cout<<"Pivot is " << getpivot(arr,n)<<endl;

    return 0;
}