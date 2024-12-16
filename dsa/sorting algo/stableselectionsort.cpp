#include<iostream>
using namespace std;
/*A sorting algorithm is said to be stable if two objects with equal or same keys appear in the same order 
in sorted output as they appear in the input array to be sorted.*/
void printarr(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void selectionsort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        cout<<"step " << i<<endl;
        int minindex=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minindex]){
                minindex=j;
            }
        }
        int key = arr[minindex]; 
      
        while(minindex>i){    
            arr[minindex]= arr[minindex-1];
            cout<<"arr["<<minindex<<"]"<< " = "<<arr[minindex] <<endl;  
            minindex -- ; 
        }
          arr[i]=key;  
          
       
        printarr(arr,n);
    }
}

int main(){
      int arr[]={64,25,12,22,11,12};
      int n=sizeof(arr)/sizeof(arr[0]);
      cout<<"This is your unsorted array"<<endl;
    printarr(arr,n);
  
    selectionsort(arr,n);
      cout<<"This is your sorted array"<<endl;
    printarr(arr,n);
    return 0;
}