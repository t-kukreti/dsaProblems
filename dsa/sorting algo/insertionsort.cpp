#include<iostream>
using namespace std;
void printarr(int arr[],int n){
    int i=0;
    while(i<n){
        cout<<arr[i]<<" ";
        i++;
    }
    cout<<endl;
}
void insertionsort(int arr[],int n){
    for(int i=1;i<n;i++){
        cout<<"Round " << i << endl;
        int temp = arr[i]; 
        int j;
        for(j=i-1;j>=0;j--){
             cout<<"j after entering loop " << j <<endl;
            if(arr[j]>temp){
                arr[j+1]=arr[j]; // arr[0+1] = 10 , j = 0
                printarr(arr,n);

            }
            else { // Stop when temp>arr[j]; 
                break;
            }
        }
            cout<<"j after exiting loop " << j <<endl;

            arr[j+1] = temp; // arr[-1 + 1] = arr[0] =  temp 
            printarr(arr,n);
        
    }
}
int main(){
    int arr[]={10,1,7,4,8,2,11};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Unsorted array : ";
    printarr(arr,n);
    cout<<"Sorted array : " ;
    insertionsort(arr,n);
    printarr(arr,n);
    return 0;
}
// Time complexity - worst case O(n*n) , best case - O(n) 
// Space complexity - O(1) 
// This is an adaptable algorithm and stable too 
// Adaptive algorithm - An adaptive algorithm is an algorithm that changes its behavior at the time it is run,[1]
// based on information available and on a priori defined reward mechanism (or criterion). Such information could 
// be the story of recently received data, information on the available computational resources,or other
// run-time acquired (or a priori known) information related to the environment in which it operates.