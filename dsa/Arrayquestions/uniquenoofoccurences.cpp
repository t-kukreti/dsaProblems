#include<iostream>
#include<algorithm>
using namespace std;
void printarr(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void uniqueoccurence(int arr[], int n){ 

   for(int i=0;i<n;i++){
    int count = 0;
    if(arr[i]==arr[i-1]){
       
        i++;
    }
    else if(arr[i]==arr[i+1]){
        i++;
    }
    for(int j=0;j<n;j++){
        if(arr[i]==arr[j]){
            count ++;
        }
    }
       
       
   }
   
 
   
  
       
}
int main(){
    
    int arr[]={1,2,2,1,1,3};
    sort(arr,arr+6);
    cout<<"This is your sorted array "<<endl;
    printarr(arr,6);
    uniqueoccurence(arr,6);

    return 0;
}