#include<iostream>
#include<algorithm>

using namespace std;

void printarr(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void duplicate(int arr[],int n){
        int i=0, j = 1;
        while(i<n){
        if(arr[i]==arr[j]){
            cout<<arr[i]<<" ";
            i++,j++;
        }
       else if(arr[i]!=arr[j]){
            i++,j++;
        }
        
        }

        }
        
int main(){

    int arr[]= {4,3,2,7,8,2,3,1};
    cout<<"This is your array "<<endl;
    printarr(arr,8);
    sort(arr,arr+8);
    cout<<"After sorting "<<endl;
    printarr(arr,8);
    cout<<"The duplicate(occurence twice) elements in the array are ";
    duplicate(arr,8);
    cout<<endl;
    
    return 0;
}