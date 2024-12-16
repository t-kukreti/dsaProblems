#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter a number " ; 
    cin>>n;
    cout<<"Your number is " << n <<endl;

    // Address of operator -> & 
    cout<<"Address of " << n << " is " << &n <<endl;
    // Pointers store the address
    // int *ptr ; means Ptr is a pointer to int data type , Data type and pointer type
    // must be similar , Bad practice
    int *ptr = &n; // * is a de-reference operator value at addresss pointed by p
    cout<< "Printing address using pointer " << ptr <<endl;
    return 0;
}