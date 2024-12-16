#include<iostream>
using namespace std;
int getsum(int *arr, int n){
    // Significance
    // You can send a particular part of an array as a parameter for eg :-
    // getsum(arr+3,3);  
    cout<<"Size of arr " << sizeof(arr) <<endl; // size of pointer
    int i = 0 , sum = 0;
    while(n>i){
         sum = sum + *(arr+i) ; // sum += arr[i] 
        i++;
    }
    return sum;
}

int main(){
    int arr[6] = {1,2,3,4,5,8};
    int ans = getsum(arr+3,3);
    cout<<"Sum is : " << ans <<endl;

    return 0;
}