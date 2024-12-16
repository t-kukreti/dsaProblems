#include<iostream>
using namespace std;
long long int squareroot(int n){
    int s=0;
    int e=n-1;
    long long int mid=s+(e-s)/2;
    int ans=0;
    while(s<e){
        long long int square = mid * mid;
        if(square == n){
            return mid;
        }
        else if(square<n){
            ans = mid;
            s=mid+1;
        }

        else{
                e=mid-1;
        }
            mid = s+(e-s)/2;
    }
    return ans;
}

double squarerootindecimal(int n, int precision, double tempans){
    double factor = 1;
    for(int i= 0;i<precision;i++){
        factor = factor /10;
        for(double j = tempans; j*j<n;j=j+factor){
            tempans=j;
        }
    }
    
    return tempans;

}

int main(){
    int n;
    cout<<"Enter the number "<<endl;
    cin>>n;
    cout<<"squareroot is "<<squareroot(n)<<endl;
    double tempans  = squareroot(n);
    cout<<endl;
    double permanentans = squarerootindecimal(n,3,tempans);
cout<<"Square root with decimals is "<<permanentans<<endl;
    return 0;
}