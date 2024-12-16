#include<iostream>
using namespace std;

int firstocc(int arr[],int n,int key){
    
int s = 0;
int e = n-1;
int ans=0;
int mid =  s + (e-s)/2;                // dont use this (start+end)/2;

while(s<=e){
    if(arr[mid]==key){
       ans= mid;
       e=mid-1;
    }
    // Go to right
    if(key>arr[mid]){
        s=mid+1;
    }
    else{ // key<arr[mid]
        e=mid-1;
    }

       mid =   s + (e-s)/2;            //mid=(start+end)/2;
   
}
 return ans;

}

int lastocc(int arr[],int n,int key){
int s = 0;
int e = n-1;
int ans=0;
int mid =  s + (e-s)/2;                // dont use this (start+end)/2;

while(s<=e){
    if(arr[mid]==key){
       ans= mid;
       s=mid+1;
    }
    // Go to right
    if(key>arr[mid]){
        s=mid+1;
    }
    else{ // key<arr[mid]
        e=mid-1;
    }

       mid =   s + (e-s)/2;            //mid=(start+end)/2;
   
}
 return ans;

}
int main(){
    int odd[]={1,2,3,3,5};
    int key = 3;
   
    cout<<"First occurence of " << key << " at index is " << firstocc(odd,5,key)<<endl;
    cout<<"Last occurence of " << key << " at index is " << lastocc(odd,5,key)<<endl;
  
    return 0;
}