#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>

using namespace std;
void printVector(vector<int> &v){
    for(int i=0; i<v.size(); i++){
        cout << v[i];
    }
    cout << endl;
}
vector<int> nextGreaterElements(vector<int> &nums){
    vector<int> ans(nums.size(), -1);
    stack<int> st;

    for(int i=0; i<2*nums.size(); i++){

        int index = i % nums.size();
        while(!st.empty() && nums[index] > nums[st.top()]){

            ans[st.top()] = nums[index];
            st.pop();
        }
        st.push(index);

    }

    return ans;
}
int main(){
    vector<int> nums = {1,2,3,4,3};
    vector<int> res = nextGreaterElements(nums);
    printVector(res);
    return 0;
}
