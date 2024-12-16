#include<iostream>
#include<vector>
using namespace std;

void printarr(vector<int> n){
    for(int i=0;i<n.size();i++){
        cout<<n[i]<<" ";
    }
    cout<<endl;
}

void rotate(vector<int> &n , int k){
    vector<int>temp (n.size());
  
    for(int i = 0;i<n.size();i++){
       
        temp[(i+k)%n.size()] = n[i];
    }
 
    n = temp;
  
   
}


int main(){
    vector<int>n ={1,7,9,11};
    
    int k;
    cout<<"Enter the point from where you want to rotate the array " ;
    cin>>k;
   
    cout<<"After rotating array by " << k <<endl; 
     rotate(n,k);
    printarr(n);
    
    return 0;
}