// swap alternate elements {1,2,3,4,5,6}
// o/p {2,1,4,3,6,5}
#include<iostream>
using namespace std;
void swaparralternate(int arr[],int n){
    int a=0; 
    int b=1;
    while(b<=n){
        swap(arr[a],arr[b]);
        a=a+2 , b= b+2;
    }
}
void printarr(int arr[], int n){
    for (int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int arr[6]={1,2,3,4,5,6};
    cout<<"array before swapping alternate elements "<<endl;
    printarr(arr,6);
    swaparralternate(arr,6);
    cout<<"array after swapping alternate elements "<<endl;
    printarr(arr,6);
    return 0;
}