#include<iostream>
#include<vector>

using namespace std;

void print_vector(vector<vector<int>> &v){
    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < v[i].size(); j++){
            cout << v[i][j]; 
        }
        cout << " ";
    }
    cout << endl;
}

void solve(vector<vector<int>> &ans, vector<int> &curr, int k, int target, int start){



    // case 1: required k elements sum up to required target 
    if(target == 0 && k == 0){
        ans.push_back(curr);
        return ; 
    }

    // case 2: required k elements doesnt sum upto target or sum gets larger than target
    if(k == 0 || target < 0){
        return ;
    }

    for(int i = start; i <= 9; i++){
        // we are allowed to choose from start (boundary)

        // i (what we chose)
        curr.push_back(i);
        solve(ans, curr, k-1, target-i, i+1);

        curr.pop_back(); // get rid of the last element 
    }

}

vector<vector<int>> combinationSum3(int k, int n){

    vector<vector<int>> ans; 
    vector<int> curr;

    solve(ans, curr, k, n, 1);


    return ans;


}

int main(){
    int k = 3, n = 7;
    vector<vector<int>> res =  combinationSum3(k, n);
    print_vector(res);

    return 0;
}