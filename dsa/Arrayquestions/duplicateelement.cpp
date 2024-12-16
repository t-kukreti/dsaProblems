#include<iostream>
#include<vector>
#include<map>
using namespace std;
void printvector(vector<int> v){
    for(int i = 0 ; i<v.size() ; i++){
        cout<<v[i] <<" ";
    }
    cout<<endl;
}
void printarr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int uniqueelement(int arr[],int n){
    int ans = 0;
    for(int i=0;i<n;i++){
        ans = (ans^arr[i]);
    }
    return ans;
}

// valid if only one duplicate element exists 
int duplicateelement(int arr[],int n){ 
    int ans=0;
    // XORing through all elements
    for(int i=0;i<n;i++){
        ans = ans^arr[i];
    }
    // XOR through 1 to n-1
    for(int i=1;i<n;i++){
        ans = ans^i;
    }
    return ans;

}

// this is valid for multiple duplicate elements 
vector<int> findduplicate(int *arr, int n){
    vector<int>ans;
    map<int,int> mp;
    for(int i = 0 ; i<n ; i++){
        mp[arr[i]] ++;
        // inserting it in ans if it's count is more than one
        if(mp[arr[i]] > 1){
            ans.push_back(arr[i]);
        }
    }
    
    // for (auto &it : mp)
    // {
    //     if (it.second > 1){
    //         ans.push_back(it.first);
    //     }
    // }
    
    return ans;

}

int main(){
//     cout<<"this is your array 1 "<<endl;
//     int arr1[] = {2,3,4,3,4,2,6};
//     printarr(arr1,sizeof(arr1)/sizeof(arr1[0]));
//    cout<<"the unique element in array1 is "<< uniqueelement(arr1,7)<<endl;

    cout<<"this is your array 2 "<<endl;
    int arr2[]= {1,1,2,2,3,4};
    vector<int>sol = findduplicate(arr2,sizeof(arr2)/sizeof(arr2[0]));
    cout<< "duplicates elements are : ";
    printvector(sol);

    // printarr(arr2,sizeof(arr2)/sizeof(arr2[0]));
//    cout<<"the duplicate element in the array2 is "<< duplicateelement(arr2,5)<<endl;
    
 
    return 0;
}