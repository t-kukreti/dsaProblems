#include<iostream>
#include<vector>
#include <stack>
#include <unordered_map>
using namespace std;

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2){
   unordered_map<int, int> nextGreater;
   stack<int> st;
   vector<int> ans;
   st.push(nums2[0]);
   for(int i=0; i<nums2.size(); i++){
       while(!st.empty() && nums2[i] > st.top()){
           nextGreater[st.top()] = nums2[i];
           st.pop();
       }
       st.push(nums2[i]);
   }
   while(!st.empty()){
       nextGreater[st.top()] = -1;
       st.pop();
   }
   for(int i=0; i<nums1.size(); i++){
       ans.push_back(nextGreater[nums1[i]]);
   }
return ans;
}

void printVector(vector<int> &v){
    for(int i=0; i<v.size(); i++){
        cout << v[i];
    }
    cout << endl;
}

int main() {
    vector<int> nums1 = {4,1,2};
    vector<int> nums2 = {1,3,4,2};
    vector<int> res = nextGreaterElement(nums1, nums2);
    printVector(res);

    return 0;
}
