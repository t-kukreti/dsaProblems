#include<iostream>
#include<vector>
using namespace std;
void printVector(vector<int> v){
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

vector<int> productExceptSelf(vector<int> &nums){
    vector<int> output(nums.size(),0);
    int ans = 1;
    int frontElemntsProduct = 1;
    int backElementsProduct = 1;
    for(int i = 0; i < nums.size(); i++){
        for(int j = i+1; j < nums.size(); j++){
            frontElemntsProduct *= nums[j];
        }
        ans = frontElemntsProduct * backElementsProduct;
        output[i] = ans;
        backElementsProduct *= nums[i];
        frontElemntsProduct = 1;
    }
    return output;
}
// sbka multiply krdo or fir divide krdo hr arr[i] se 
vector<int> product(vector<int> &v){
    vector<int> ans(v.size(),0);
    int countOfZeroes = 0, product = 1, index = -1;
    for(int i = 0; i < v.size(); i++){
        if(v[i] == 0){
            index = i;
            countOfZeroes ++;
        }
        else{
            product *= v[i];
        }
    }
    if(countOfZeroes > 1){
        return ans;
    }
    else if(countOfZeroes == 1){
        ans[index] = product;
        return ans;
    }
    else{
        for(int i = 0; i < v.size(); i++){
            ans[i] = product / v[i];
        }
    }
    return ans;

}

vector<int> optimised(vector<int> &nums){
    vector<int> ans;
    vector<int> frontProductsArr;
    vector<int> backProductsArr;
    int frontProduct = 1, backProduct = 1;
    for(int i = 0, j = nums.size()-1; (i < nums.size() && j >= 0) ; i++,j--){
        if(i == 0 && j == nums.size()-1){
            backProductsArr.push_back(1);
            frontProductsArr.push_back(1);
        }
        else{
            backProduct *= nums[i-1], frontProduct *= nums[j+1];
            backProductsArr.push_back(backProduct);
            frontProductsArr.push_back(frontProduct);
        }
    }
    int i = 0, j = frontProductsArr.size()-1;
    while( (i < backProductsArr.size() && j >= 0) ){
        ans.push_back(frontProductsArr[j] * backProductsArr[i]);
        i++, j--;
    }
    return ans;
}
int main(){
    vector<int> nums = {3,2,4,6}; 
    vector<int> ans = optimised(nums);
    printVector(ans);
    return 0;
}