#include<iostream>
#include<algorithm>
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
// standard way
void solve(vector<vector<int>>&ans, vector<int> &candidates, vector<int> &current, int target, int index){
        // base conditions 
        if(target == 0){
        ans.push_back(current);
        return;
        }
    if(target < 0){
        return;
    }
    if(index == candidates.size()){
        return;
        }

        for(int i = index; i < candidates.size(); i++){
        if(i > index && candidates[i] == candidates[i-1]) continue;
        
        current.push_back(candidates[i]);
        solve(ans,candidates,current,(target - candidates[i]),i+1);
        current.pop_back();
        
        }
        
        }
        /*
        void solve(vector<vector<int>>&ans, vector<int> &candidates, vector<int> &current, int target, int index){
            
        // base conditions 
        if(target == 0){
            ans.push_back(current);
            return;
    }
    if(target < 0){
        return;
    }
    if(index == candidates.size()){
        return;
    }
    
    // take 
    current.push_back(candidates[index]);
    solve(ans,candidates,current,(target-candidates[index]), index+1);
    current.pop_back();
    
    // duplicate check 
    int nextIndex = index;
    if( (index != candidates.size()-1) && (candidates[index] == candidates[index+1])){
        nextIndex = index;
        while(nextIndex < candidates.size()-1 && candidates[nextIndex] == candidates[nextIndex+1]){
            nextIndex++;
        }
    }
    
    // skip condition
    solve(ans,candidates,current,target, nextIndex+1);
    
    
}
*/

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> current;
    sort(candidates.begin(), candidates.end());
    solve(ans, candidates, current, target, 0);
    return ans;            
}

int main(){
    vector<int> candidates = {2,5,2,1,2};
    int target = 5; 
    vector<vector<int>> res = combinationSum2(candidates, target);
    print_vector(res);

    return 0;
}