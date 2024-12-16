#include<iostream>
#include<vector>
using namespace std;
 void rotateimage(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int j = 0 ; j < n ; j++){
            for(int i = n -1 ; i>=0; i--){
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }
int main(){
    vector<vector<int>> matrix {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    rotateimage(matrix);
    return 0;
}