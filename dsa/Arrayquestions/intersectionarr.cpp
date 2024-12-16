#include<iostream>
using namespace std;
void printarr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void commonelement(int arr1[],int arr2[],int n,int m){
    int i=0, j =0;
    cout<<"These are the common elements in both the given arrays { ";
    while(i<n || j<m){
        if(arr1[i]<arr2[j]){
            i++;
        }
        else if(arr1[i]==arr2[j]){
            cout<<arr1[i]<<" ";
            i++, j++;
        }
        else(arr1[i]>arr2[j]);{
            j++;
        }
    }
    cout<<"}";
}

int main(){
    // arrays are given in sorted decreasing order in question otherwise we have to sort them
    // for two pointer approach
    cout<<"This is your array 1"<<endl;
    int arr1[]={1,2,2,2,3,4}; // 2,2,3
    printarr(arr1,6);
    cout<<"This is your array 2"<<endl;
    int arr2[]={2,2,3,3};
    printarr(arr2,4);

    commonelement(arr1,arr2,6,4);
    return 0;
}