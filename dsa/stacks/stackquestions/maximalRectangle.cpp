#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> nextSmallElement(vector<int>v, int n){
    stack<int> st;
    vector<int>ans(n);
    st.push(-1);

    for(int i = n-1 ; i>= 0 ; i--){
        while(st.top()!=-1 && v[st.top()] >= v[i]){
            st.pop();
        }
        ans[i] = st.top();
        st.push(i);
    }
    return ans;

}
vector<int> prevSmallElement(vector<int>v, int n){
        stack<int> st;
    vector<int>ans(n);
    st.push(-1);

    for(int i = 0 ; i<n; i++){
        while(st.top()!=-1 && v[st.top()] >= v[i]){
            st.pop();
        }
        ans[i] = st.top();
        st.push(i);
    }
    return ans;
}

int maxRectangularArea(vector<int> v){
    int n = v.size();
    vector<int> next_Small_Element_indexes(n);
    next_Small_Element_indexes = nextSmallElement(v,n);
    vector<int> prev_Small_Element_indexes(n);
    prev_Small_Element_indexes = prevSmallElement(v,n);

    int area = -1;
    for(int i = 0 ; i<n; i++){
        int length = v[i];
        if(next_Small_Element_indexes[i] == -1){
            next_Small_Element_indexes[i] = n;
        }
        int breadth = next_Small_Element_indexes[i] - prev_Small_Element_indexes[i] - 1;

        int newArea = length * breadth;
        area = max(area,newArea);
    }

    return area;
}

int maximalRectangle(vector<vector<int>> &matrix){
    int rows = matrix.size();
    int col = matrix[0].size();
    // step 1: compute the area for first row 
    int area = maxRectangularArea(matrix[0]);
    for(int i = 1 ; i<rows; i++){
        for(int j = 0 ; j<col; j++){
            // step2: update the row by adding previous row to it
            if(matrix[i][j] != 0){
                matrix[i][j] = matrix[i][j] + matrix[i-1][j];
            }
            else{
                matrix[i][j] = 0;
            }     
        }
        // step3: entire row updated, just find area and see if it's max or not
        area = max(area,maxRectangularArea(matrix[i]));
    }
    return area;
}

int main(){
    vector<vector<int>> matrix = {
    {1,0,1,0,0},
    {1,0,1,1,1},
    {1,1,1,1,1},
    {1,0,0,1,0}
    };
cout<<"maximum area is " << maximalRectangle(matrix) <<endl;


    
    return 0;
}