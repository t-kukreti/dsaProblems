#include<iostream>
#include<typeinfo>
#include<vector>
using namespace std;
void print(vector<int> v){
    for(int i = 0 ; i < v.size() ; i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
vector<vector<int>> convertCharToInt (vector<vector<char>> v){
    vector<vector<int>> ans(v.size());
    for(int i = 0 ; i<v.size() ; i++){
        ans[i].resize(v[i].size());
        for(int j = 0 ; j<v[0].size(); j++){
            ans[i][j] = v[i][j] - '0';
        }
    }
    return ans;
}
// this getnextsmall and prevnextsmall is buggy need to resolve it in order to pass test case and submit the solution, we are getting heap buffer error. 
// update - tried it, removed the heap buffer bug too but it's not efficient for large inputs need to check this later again 
// and stack approach is O(n); 
vector<int> getNextSmall(vector<int> v, int n){
    vector<int> ans(n);

    int i = 0 , j = i+1;
    while(i < n){
        if(v[i] > v[j] && j<=n){
            ans[i] = j;
            i++ , j = i+1;
        }
        else{
            j++;
            if(j == n-1){
                ans[i] = n;
                i++, j = i+1;
            }
        }
    }
    print(ans);
    return ans;
}
vector<int> getPrevSmall(vector<int>v, int n){
    vector<int> ans(n);
    int i = 0 , j = i-1;
    while(i < n){
        if(j == -1){
            ans[i] = j;
            i++ , j = i-1;
        }
        if(v[i] > v[j]){
            ans[i] = j;
            i++, j = i-1;
        }

        else{
            j--;
        }

    }
    print(ans);
    return ans;
}

int maxArea(vector<int> v){
    int n = v.size();
    vector<int> nextSmallElementIndex(n);
    nextSmallElementIndex = getNextSmall(v,n);
    vector<int> prevSmallElementIndex(n);
    prevSmallElementIndex = getPrevSmall(v,n);

    int maxarea = -1;
    for(int i = 0 ; i<n; i++){
    int area = v[i] * (nextSmallElementIndex[i] - prevSmallElementIndex[i] -1);
    maxarea = max(area , maxarea);
    }
    return maxarea;
}
int maximalRectangle (vector<vector<int>> v){
    int area = maxArea(v[0]);
    for(int i = 1; i<v.size(); i++){
        for(int j = 0 ; j<v[i].size(); j++){
            if(v[i][j] == 0){
                v[i][j] = 0;
            }
            else{
                v[i][j] = v[i][j] + v[i-1][j];
            }

        }
        area = max(area , maxArea(v[i]));
    }
    return area;
}

int main(){
     vector<vector<char>> matrix = {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}
    };
    vector<vector<int>> intVector = convertCharToInt(matrix);
    int ans = maximalRectangle(intVector);
    cout<<"Maximum area of rectangle constituted by 1 is : " << ans << endl;

    // tells you what type it is 
//    const std::type_info& typematrix = typeid(intVector);
//    cout<<"type of matrix " << typematrix.name() <<endl;

    
    return 0;
}