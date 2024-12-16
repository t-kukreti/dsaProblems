#include<iostream>
using namespace std;

int main(){
    int j;
    int n ;

    cin >>n;
    int arr[n];
    for(int i=0;i<n;i++){
     cin >> arr[i];
     }
     for(int i=1;i<=n;i++){
        cout<<arr[n-i]<<" ";
     }
    /* cout<<arr[n-1];
     cout<<arr[n-2];
     cout<<arr[n-3];
     cout<<arr[n-4];
     cout<<arr[n-5];
     cout<<arr[n-6];*/
     
}