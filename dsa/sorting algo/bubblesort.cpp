#include<iostream>
using namespace std;
// Homework
/*
What is stable algorithm ?
If two objects with equal keys appear in the same order in sorted output as they appear in the input,
 an unsorted array of elements then the algorithm used for sorting is a stable sort algorithm
*/
// Check bubblesort is inplace sort or not   it is inplace sort
// Check its stable or not  its stable meaning it preserves the realtive order of the elements
/*
Inplace sort ?
In-Place Sorting algorithm-> A Sorting algorithm which don’t take extra space other than your given array .
It means in a algorithm do not create an array externally to sort an elements ,
then that type of algorithm known as in - place algorithm .
that types algorithms space complexity generally is constant space is required to sort an elements.
*/

void printarr(int arr[],int n){
    int i=0;
    while( i<n){    
        cout<<arr[i]<<" ";
        i++;

    }
    cout<<endl;
}   
/*
Sort by comparing each adjacent pair of items in a list in turn, swapping the items if necessary,
and repeating the pass through the list until no swaps are done. Also known as sinking sort, exchange sort.
*/
// In round ith , ith largest element get placed at its right position (that's what bubble sort do)
void bubblesort(int arr[],int n){
    for(int i= 1;i<n;i++){
        bool swapped = false;  // for optimization In best case time complexity will be O(n)
        cout<<"Round " << i <<endl;
        for(int j = 0;j<(n-i);j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                swapped = true;
                printarr(arr,n);
            }
        }
         if(swapped == false){
            // already sorted
        break;
    }
    }
   
}
int main(){
    int arr[]= {10,1,7,6,14,9};
    int n= sizeof(arr)/sizeof(arr[0]);
    cout<<"This is your unsorted array " <<endl;
    printarr(arr,n);
   
    bubblesort(arr,n);
     cout<<"This is your sorted array " << endl;
    printarr(arr,n);

    return 0;
}
// Tc  worstcase O(n*n)
// Sc  O(1)
// Solve quiz on bubblesort (gfg link in bubblesort video description)