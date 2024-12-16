#include<iostream>
#include<vector>
using namespace std;
// tc -> O(m+n) 
// there's an algo named "median of two sorted array" for doing this is O(log(m+n));
void print(vector<int> v){
    for(int i = 0 ; i<v.size() ; i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

vector<int> mergearr(vector<int> &v1 , vector<int> &v2){
    vector<int> ans;
    if(v1.size() == 0){
        return v2;
    }
    else if(v2.size() == 0){
        return v1;
    }

    int i = 0, j = 0;
    while( i<v1.size() && j<v2.size() ){
        if(v1[i] <= v2[j]){
            ans.push_back(v1[i]);
            i++;
        }
        else{
            ans.push_back(v2[j]);
            j++;
        }
    }
    while(i<v1.size()){
        ans.push_back(v1[i]);
        i++;
    }
    while(j<v2.size()){
        ans.push_back(v2[j]);
        j++;
    }
    return ans;
}

 double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> mergedArr = mergearr(nums1,nums2);
        print(mergedArr);

        int length = mergedArr.size();
        int mid;

        if(length & 1){
            mid = length/2;
            return mergedArr[mid];
        }
        else{
            mid = length/2;
            double ans = static_cast<double> (mergedArr[mid] + mergedArr[mid-1])/2;
            return ans;
        }
        return -1;
    }

int main(){
    vector<int> nums1 = {1,3};
    vector<int> nums2 = {2,4};

    double ans = findMedianSortedArrays(nums1,nums2);
    cout<<ans << endl;
    
    return 0;
}