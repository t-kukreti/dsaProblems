#include<iostream>
#include<vector>
using namespace std;
void printarr(vector<int> n){
    for(int i=0;i<n.size();i++){
        cout<<n[i]<<" ";
    }
    cout<<endl;
}

vector<int> reverse(vector<int> &v ){
    int s= 0 ;
    int e = v.size()-1;
    while(s<e){
        swap(v[s++],v[e--]);
    }
    return v;
}

vector<int> sum( vector<int> &arr1 , int n , vector<int> &arr2 ,int m  ){
    int i = n-1 , j = m-1;
    int carry = 0;
    vector<int>ans;
    while(i>=0 && j>=0){
        int val1 = arr1[i];                 // 4
        int val2 = arr2[j];                 // 6
        int sum = val1 + val2 + carry;     // 10 + 0
        carry = sum/10;                    // 1
        sum = sum % 10;                    // 0
        ans.push_back(sum);
        i-- , j--;
    }

    while(i>=0){
        int sum = arr1[i] + carry;
         carry = sum/10;
        sum = sum % 10;
        ans.push_back(sum);
        i--;
    }
    while(j>=0){
          int sum = arr2[j] + carry;
         carry = sum/10;
        sum = sum % 10;
        ans.push_back(sum);
        j--;
    }
    while (carry!=0){
        int sum = carry;
        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);

    }
    return reverse(ans);

}



int main(){
    vector<int> arr1 = {1,2,3,4};
    int n = arr1.size();
    vector<int> arr2 = {6};
    int m = arr2.size();
  printarr(sum(arr1,n,arr2,m));  

    return 0;
}

