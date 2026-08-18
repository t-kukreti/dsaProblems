#include<iostream>
#include<vector>
#include<climits>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int total_length = nums1.size() + nums2.size();

    if(nums1.size() > nums2.size()){
        swap(nums1,nums2);
    }

    int left = 0, right = nums1.size();
    int left_partition = (total_length + 1) / 2;
   
    while(left <= right){
        int mid = left + (right - left) / 2;
        int cut1 = mid, cut2 = left_partition - cut1;

        int l1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
        int r1 = (cut1 == nums1.size()) ? INT_MAX : nums1[cut1];

        int l2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
        int r2 = (cut2 == nums2.size()) ? INT_MAX : nums2[cut2];

        // check boundary 
        if((l1 <= r2) && (l2 <= r1)){
            if((total_length & 1)){
                // odd
                return max(l1,l2);
            }
            else{
                // even
                return (max(l1,l2) + min(r1,r2)) / 2.0;
            }
        }
        else if(l1 > r2){
            right = mid - 1;
        }
        else if (l2 > r1) {
            left = mid + 1;
        }
    }
    return -1;
}

int main(){
    vector<int> nums1 = {1,3,8,9,15};
    vector<int> nums2 = {7,11,18,19};

    cout << findMedianSortedArrays(nums1, nums2) << endl;    
    return 0;

}