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

void solve(vector<vector<int>> &ans, vector<int> &candidates, vector<int> &current, int target, int index){

    // base cases 
    if(target == 0){
        ans.push_back(current);
        return;
    }

    if(target < 0){
        // current window not valid.
        return;
    }

    if(index == candidates.size()){
        return ;
    }

    // take current candidate
    current.push_back(candidates[index]);
    solve(ans,candidates,current,(target-candidates[index]),index);

    current.pop_back();

    // skip current candidate
    solve(ans,candidates,current,target, index+1);
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> current;

    solve(ans, candidates, current, target, 0);

    return ans;
}
int main(){
    vector<int> candidates = {2,3,5};
    int target = 8;
    vector<vector<int>> res = combinationSum(candidates, target);
    print_vector(res);

    return 0;

}