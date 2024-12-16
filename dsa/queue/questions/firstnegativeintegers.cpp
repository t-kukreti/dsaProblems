#include<iostream>
#include<deque>
#include<vector>
using namespace std;
void print(vector<int> v){
    for(int i = 0; i < v.size() ; i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

vector<int> firstNegativeIntegers(vector<int> arr, int k){
    vector<int> ans;
    deque<int> window;
    for(int i = 0; i < arr.size(); i++){
        if(!window.empty() && window.front() <= i-k){
            window.pop_front();
        }
        if (arr[i] < 0){
            window.push_back(i);
        }
        // three numbers or more in current window
        if(i >= k-1){
            if(window.empty()){
                ans.push_back(0);
            }
            else{
                ans.push_back(arr[window.front()]);
            }
        }
    }   
    return ans;
}
int main(){
    vector<int> arr = {-8,2,3,-6,10};
    int k = 3;
    vector<int> ans = firstNegativeIntegers(arr,k);
    print(ans);
    return 0;
}