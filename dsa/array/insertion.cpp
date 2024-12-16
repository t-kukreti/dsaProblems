#include<iostream>
using namespace std;

void printArray(int a[], int n){
    for(int i=0; i<n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

void insertAfterLastFilledElement(int a[], int n, int data){
    if(a[n-1] != 0){
        cout << "array is full, was inserting " << data  << endl;
        return ;
    }
    for(int i=0; i<n; i++){
        if(a[i] == 0){
            a[i] = data;
            break;
        }
    }
}


int main(){
    int arr[10] = {1,2,3};
    printArray(arr,10);
    insertAfterLastFilledElement(arr,10,4);
    insertAfterLastFilledElement(arr,10,5);
    insertAfterLastFilledElement(arr,10,6);
    insertAfterLastFilledElement(arr,10,7);
    insertAfterLastFilledElement(arr,10,8);
    insertAfterLastFilledElement(arr,10,9);
    insertAfterLastFilledElement(arr,10,10);
    insertAfterLastFilledElement(arr,10,11);
    printArray(arr,10);




    return 0;
}