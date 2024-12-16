// this program is to calculate the variance of the given numbers
#include<iostream>
#include<cmath>
using namespace std;
float sum(float arr[],float n){
    
    
 float sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    return sum;
}
float variance(float arr[],float n){
    
    
   float variance=0;
    for(int i=0;i<n;i++){
       variance+=pow(sum(arr,n)/n - arr[i],2);
    }
    return variance;
}
/*float standarddeviation(float arr[],float n){
    
    
  float standarddeviation=0;
    for(int i=0;i<n;i++){
       standarddeviation+=pow(sum(arr,n)/n - arr[i],0.5);
    }
    return standarddeviation;
}*/
int main(){
    int n;
    cout<<"enter how many numbers you want to add:"<<endl;
    cin>>n;
    cout<<"enter your numbers with a spacebar in between or you can enter one digit and hit enter then enter another digit :"<<endl;
   float arr[n];
     for(int i=0;i<n;i++){
        cin>>arr[i];}
    cout<<"the sum is:"<<sum(arr,n)<<endl;
    cout<<"the mean  is: " <<sum(arr,n)/n<<endl;
    cout<<"the variance is "<<variance(arr,n)/n<<endl; 
    cout<<"the standard deviation is: "<<pow(variance(arr,n)/n,0.5);
    return 0;
}