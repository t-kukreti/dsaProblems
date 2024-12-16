#include<iostream>
using namespace std;
// Dynamic memory allocation and reference variables code is in computer

int main(){
   // int arr[5][5]; // declaration using stack memory
    int row , col ;
    cout<<"Enter row and columns " << endl;
    cin>> row >> col;
    // int arr[row][col] ; Bad practice 
    // for one D array
 //   int * arr = new int [row]; // dynamic 

 // for 2 D array 
 int ** arr = new int *[row]; // Right now only pointers are there 
//  but we want that there should be an array to every corresponding pointer 
for(int i = 0 ; i<row ; i++){
    arr[i] = new int[col];
}
// 2d array created 
// Taking input
cout<<"Enter input " << endl;
for(int i = 0 ; i < row ; i++){
    for(int j = 0; j<col;j++){
        cin>>arr[i][j];
    }
}
cout<<"Printing the 2d array " << endl;
for(int i = 0 ; i < row ; i++){
    for(int j = 0; j<col;j++){
        cout<<arr[i][j]<<" ";
    }
    cout<<endl;
}
// Releasing memory
for(int i = 0 ; i < row ; i++){
    delete [] arr[i]; // all col associated with row (arr *)
}

delete [] arr;

// Always remember after assigning heap memory you have to free it manually after completion of that task 
    return 0;
}