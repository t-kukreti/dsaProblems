#include<iostream>
#include<vector>
#include<stack>
using namespace std;
void print(vector<int>v){
    for(int i = 0 ; i<v.size() ; i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
vector<int> nextSmallIndex(vector<int> v){
    int n = v.size();
    vector<int> ans(n);

    int i = 0, j = i+1;
    while(i < n){
        if(v[i] > v[j]){
            ans[i] = j;
            i++;
            j=i+1;
        }
        else if(v[i] <= v[j]){
            j++;
            if(j == n){
                ans[i] = n;
                i++;
                j=i+1;
            }
        }      
    }
    return ans;
}
vector<int> prevSmallIndex(vector<int>v){
    int n = v.size();
    vector<int> ans(n);

    int i = 0, j = i-1;
    while(i < n){
        if(j == -1){
            ans[i] = j;
            i++;
            j = i-1;
        }
        if(v[i] > v[j] ){
            ans[i] = j;
            i++;
            j = i-1;
        }
        else if(v[i] <= v[j]){
            j--;
        }
    }
}
vector<int> getNextSmall_Index(vector<int> v){
    vector<int> smallIndexOfElement(v.size());
    stack<int>st;
    // the next small element of last index element is not present
    st.push(-1);
    for(int i = v.size()-1 ; i>=0; i--){
        while( (st.top() != -1) && (v[st.top()] >= v[i]) ){
            st.pop();
        }
        smallIndexOfElement[i] = st.top();
        // if its -1 that means no smaller element was present and this implies that starting from its index it can cover the whole vector size so it's breadth can't be -1, it should be vector's size.
        if(smallIndexOfElement[i] == -1){
            smallIndexOfElement[i] = v.size();
        }
        st.push(i);
    }
    return smallIndexOfElement;
}
vector<int> getPrevSmall_Index(vector<int>v){
    vector<int> smallIndexOfElement(v.size());
    stack<int>st;
    st.push(-1);

    for(int i = 0 ; i<v.size(); i++){
        while((st.top() != -1 ) && (v[st.top()] >= v[i])){
            st.pop();
        }
        smallIndexOfElement[i] = st.top();
        st.push(i);
    }
    return smallIndexOfElement;
}
int maxArea(vector<int>v){
    vector<int> nextSmall_Index(v.size());
    nextSmall_Index = getNextSmall_Index(v);

    vector<int> prevSmall_Index(v.size());
    prevSmall_Index = getPrevSmall_Index(v);

    int maxArea = -1;
    for(int i = 0 ; i<v.size(); i++){
    int area = v[i] * (nextSmall_Index[i] - prevSmall_Index[i] - 1);
    maxArea = max(area,maxArea);

    }
    return maxArea;
}


int maximalRectangle(vector<vector<int>> &matrix){
    // first row
    int area = -1;
 
    area = maxArea(matrix[0]);

    for(int i = 1 ; i<matrix.size(); i++){
        for(int j = 0 ; j<matrix[i].size(); j++){
            if(matrix[i][j] != 0){
                matrix[i][j] = matrix[i][j] + matrix[i-1][j];
            }
            else{
                matrix[i][j] = 0;
            }
        }
        area = max(area , maxArea(matrix[i]));
    }
    return area;
}

vector<vector<int>> convertToIntVector(vector<vector<char>> &v){
    vector<vector<int>> intVector(v.size());
    for(int i = 0 ; i<v.size() ; i++){
        intVector[i].resize(v[i].size()); // resize the innervector of intvector to corresponding innersize of v vector
        for(int j = 0 ; j<v[0].size(); j++){
            int element = v[i][j] - '0';
            intVector[i][j] = element;
        }
    }
    return intVector;
}




int main(){
    vector<vector<char>> matrix = {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}
    };
    vector<vector<int>> intMatrix = convertToIntVector(matrix);
    cout<<"this is two pointer approach "<<endl;
    print(intMatrix[0]);
    print(prevSmallIndex(intMatrix[0]));
    // int ans = maximalRectangle(intMatrix);
    // cout<<"Maximum area constituted by '1' is:  " << ans <<endl;
    return 0;
}

