#include<iostream>
using namespace std;
void printarr(int ans[],int n){
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

void movezeroes(int arr[],int n ){
  
    int nonzero = 0;
        for(int j = 0;j<n;j++){
            if(arr[j]!=0 ){
                swap(arr[j],arr[nonzero++]);
            }
        }

    }


int main(){
    int arr[] = {0,1,0,3,12};
    int n = sizeof(arr)/sizeof(arr[0]);
    movezeroes(arr,n);
    printarr(arr,n);
    return 0;
}