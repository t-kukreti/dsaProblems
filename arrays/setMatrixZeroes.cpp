#include<iostream>
#include<vector>

using namespace std;


void printMatrix(vector<vector<int>> &v){
    for(int i=0; i<v.size(); i++){
        for(int j=0; j<v[i].size(); j++){
            cout << v[i][j] << "";
        }
        cout << endl;
    }
    cout << endl;
}
void setZeroes(vector<vector<int>> &matrix){
    vector<bool> seenRows(matrix.size(), false);
    vector<bool> seenCols(matrix[0].size(), false);

    // traverse the whole matirx, mark true to row, col if element = 0
    for(int row=0; row<matrix.size(); row++){
        for(int col=0; col<matrix[row].size(); col++){
            if(matrix[row][col] == 0){
                seenRows[row] = true;
                seenCols[col] = true;
            }
        }
    }

    // again traverse and set the zeroes where seenRows[row] || seenCols[col] = true

    for(int row=0; row<matrix.size(); row++){
        for(int col=0; col<matrix[row].size(); col++){
            if(seenRows[row] || seenCols[col]){
                matrix[row][col] = 0;
            }
        }
    }


}

// using o(1) space, using the matrix first row/col itself as markers.
// [works cause the whole row / col needs to be zeroed. so any row that has element zero, is getting all zerores, if in a differnt row, col check will handle that particular column
void setZeroesOptimally(vector<vector<int>> &matrix){
    // mark the first row/col = 0
    bool firstRowZero = false;
    bool firstColZero = false;
    for(int row = 0; row < matrix.size(); row++){
        for(int col = 0; col < matrix[row].size(); col++){
            if(matrix[row][col] == 0){
                if(row == 0) firstRowZero = true;
                if(col == 0) firstColZero = true;
                matrix[row][0] = 0;
                matrix[0][col] = 0;
            }
        }
    }

    // traverse again and mark value of elements 0, based on row and col
    for(int row = 1; row < matrix.size(); row++){
        for(int col = 1; col < matrix[row].size(); col++){
            if(matrix[row][0] == 0 || matrix[0][col] == 0){
                matrix[row][col] = 0;
            }
        }
    }

    if(firstRowZero){
        for(int col = 0; col < matrix[0].size(); col++){
            matrix[0][col] = 0;
        }

    }
    if(firstColZero){
        for(int row = 0; row < matrix.size(); row++){
            matrix[row][0] = 0;
        }

    }
}
int main(){

    vector<vector<int>> matrix = {
        {0, 1, 2, 0},
        {3, 4, 5, 2},
        {1, 3, 1, 5},
    };

    setZeroesOptimally(matrix);
    printMatrix(matrix);

    return 0;
}