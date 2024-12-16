#include<iostream>
using namespace std;
/*
int main(){
  
    int max;
    int n,i;
    cin>>n;
    int array[n]; 
    for(int i =0;i<n;i++){
         cin>>array[i];
         cout<<array[i]<<" ";
    }
  max=array[0];
    for(int j=1;j<n;j++){
            if(array[j]>max){
                    max=array[j];
            }
    }
cout<<"the memory allocated to array is :"<<sizeof(array);
cout<<"the largest number in the given array is: "<<max;


    return 0;
}*/
int largest(int array[],int n){
    int max;
    max=array[0];
for(int i =1;i<n;i++){
    if(array[i]>max){
    max=array[i];
}
}
return max;
}


int main(){
    int n;
    cout<<"enter the value of n:";
    cin>>n;
    int array[n];
    for(int i =0;i<n;i++){
        cin>>array[i];
    }
cout<<"the largest number in the array is : "<<largest(array,n);

    return 0;
}
// there is one more way by using the *max_element() check it and use it 