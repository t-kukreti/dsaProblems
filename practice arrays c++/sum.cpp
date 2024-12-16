// sum of elements in a given array 
#include<iostream>
using namespace std;
/*int sum (int arr[],int n){
    int sum =0;
    for(int i=0; i<n;i++){
        sum+=arr[i];
    }
       return sum;
}*/
int sum (int arr[],int n){
    int sum =0;
    for(int i=0; i<n;i++){
        sum+=arr[i];
    }
       return sum;
}
/*int dos(int arr[],int n){
  dos+=(sum/n)

}*/
int main(){
    int n;
    cout<<"how many numbers you want to put :"<<endl;
    cin>>n;
int arr[n];
    for(int a =0;a<n;a++){
        cin>>arr[a]; 
    }
    cout<<"total memory(bytes) allocated to this array: "<<sizeof(arr)<<endl; // as this is a int array each element gets a 4 bytes
        cout<<"memory of single element in an array: "<<sizeof(arr[0])<<endl; // this will give u 4 bytes
     cout<<"no. of elements in the array: "<<sizeof(arr)/sizeof(arr[0])<<endl; 
   /* n=sizeof(arr)/sizeof(arr[0]); 
If you have an array then sizeof(array) returns the number of bytes the array occupies.
 Since each element can take more than 1 byte of space, you have to divide the result with the size of one element (sizeof(array[0])). 
This gives you number of elements in the array.*/

cout<<"sum of given array is : "<<sum(arr,n) <<endl;
cout<<"mean of given array is : "<<sum(arr,n)/n <<endl;
    return 0;
}