#include<iostream>
using namespace std;
// what is a majority element ----> when frequency of occuring of an element is greater than n/2(where n is the no of elements in an array)

int main(){
    int count;
    int maxcount =0;
    int n,i,a;
    int index;
    cin>>a;
    int arr[a];
    for(int b=0;b<a;b++){
        cin>>arr[b];
    }
    for(int i=0;i<a;i++){
        int count =0;
        for(int j=1;j<a;j++){
        if(arr[i]==arr[j]){
            count++;
        }
        }
         if(count>maxcount){
        maxcount=count;
        index=i;
     }
     
    }
    for(int i=0;i<a;i++){
    cout<<"the count of" <<i<<":"<<maxcount<<endl; }
    //cout<<maxcount<<endl;
    n=sizeof(arr)/sizeof(arr[0]);
    cout<<"  the size of this array is: "<<sizeof(arr)<<"bytes"<<endl;
    if(maxcount>n/2){
cout<<"majority element is:"<<arr[index];
    }
    else{cout<<"no majority element"<<endl;
    }
 
     return 0;
}