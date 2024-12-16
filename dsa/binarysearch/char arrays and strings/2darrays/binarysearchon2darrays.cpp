#include<iostream>
#include<vector>
using namespace std;
bool searchmatrix(vector<vector<int>> &matrix , int target ){
    int row = matrix.size();
    int col = matrix[0].size();
    int start = 0 ;
    int end = row * col -1;
    int mid = start + (end - start)/2;

    while(start<=end){
        int element = matrix[mid/col][mid%col];
        if(element == target){
            cout<<"The target is present " <<endl;
            return 1;
        }
        if(element < target){
            start = mid + 1;
        }
        else { // element > target 
            end = mid - 1;
        }
        mid = start + (end - start)/2;

    }
    cout<<"The target is not present " <<endl;
    return 0;
}

int main(){
    vector<vector<int>> matrix {
        {1,3,5,7},
        {10,11,16,20},
        {23,30,34,60}
    };
    int target = 11;
    cout<<searchmatrix(matrix , target);
    
    return 0;
}