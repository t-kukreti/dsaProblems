#include<iostream>
using namespace std;
// Not a stable algorithm and in-place is also not sure some say it is some say its not 
void print (int *arr,int s ,int e){
    for(int i = s ;i<=e ; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int partition(int *arr,int s,int e){
    int pivot = arr[s] , count = 0;
    for(int i = s+1; i<=e ; i++){
        if(arr[i]<=pivot){
            count ++;
        }
    }
    int pivotindex = s + count ;
    swap(arr[pivotindex],arr[s]);
    int i = s , j = e ; 
    while(i<pivotindex && j>pivotindex){
        while(arr[i]<=pivot && i<j){   // i<j makes sure that it doesn't passes pivotindex if it does it's gonna mess up things 
            i++;
        }
        while(arr[j]>pivot && i<j){
            j--;
        }
        if(arr[i]>=arr[pivotindex] && arr[j]<=arr[pivotindex] && i<j){
            swap(arr[i++],arr[j--]);
        }
    }
    return pivotindex;
    
}
void quicksort(int *arr,int s ,int e){
    if(s>=e){
        return ;
    }
    int p = partition(arr,s,e);
    quicksort(arr,s,p-1);
    quicksort(arr,p+1,e);
}
int main(){
    int arr[] = {3,1,5,1,1,8,2,2,4};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"Before sorting : ";
    print(arr,0,size-1);
    quicksort(arr,0,size-1);
    cout<<"After sorting : " ;
    print(arr,0,size-1);
 
  
    
    return 0;
}