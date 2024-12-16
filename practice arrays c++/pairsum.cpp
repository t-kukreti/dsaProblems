#include<iostream>
using namespace std;
int check(int arr[],int sum,int n){
    
    int x =-2;
for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
        sum =arr[i]+arr[j];
   cout<<"the sum of "<<arr[i]<< "+" <<arr[j]<< "=" << sum<<endl;
   if(sum==x){
    cout<<"yes the pair exist , it is "<<arr[i]<< " and " <<arr[j]<<"and adding these two will get " <<sum <<endl;
    return 1;
   }
    }
    cout<<endl;
    
}
cout<<"no such pair exist"<<endl;
return 0;
}

int main(){
   
    
    int arr[]={0,-1,2,-3,1};
    int n;
    n=sizeof(arr)/sizeof(arr[0]);
    int x = -2;
    //cout<<n;
     int sum;
check(arr,sum,n);

    return 0;

}