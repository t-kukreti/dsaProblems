#include<iostream>
using namespace std;


int firstelement(int arr[],int n, int key){
    
    int s=0 ,ans=0;
    int e=n-1;
    int m = (s+e)/2;
    while(s<=e){
            if(arr[m]==key){
                    ans = m ;
                    e = m-1;

            }
            else if(arr[m]>key){
                    e=m-1;
            }
            else {
                s=m+1;
            }
    m = (s+e)/2;
    }
    return ans;
}
int lastelement(int arr[],int n, int key){
    
    int s=0 ,ans=0;
    int e=n-1;
    int m = (s+e)/2;
    while(s<=e){
            if(arr[m]==key){
                    ans = m ;
                    s=m+1;

            }
            else if(arr[m]>key){
                    e=m-1;
            }
            else {
                s=m+1;
            }
    m = (s+e)/2;
    }
    return ans;
}

int main(){
    int i=0;
        int arr[]={1,2,3,3,3,3,3,3,5};
     int key = 3;
     int n = sizeof(arr)/sizeof(arr[0]);
     cout<< n <<" number of elements are present in the array "<<endl;
     cout<<"This is your key : "<<key<<endl;
     cout<<endl;
while(i<n){
    if(arr[i]==key){
        cout<<"Key is present in the array "<<endl;
         cout<<"The first position of element " << key << " is " << firstelement(arr,n,key)<<endl;
     cout<<"The last position of element " << key << " is " << lastelement(arr,n,key)<<endl;
     cout<<"Total number of occurences of " << key << " is " << (lastelement(arr,n,key) - firstelement(arr,n,key)) +1 <<endl;
   break;
    }
    
    i++;
}
cout<<endl;
cout<<"Key is not present in the array "<<endl;
    
    return 0;
}