#include<iostream>
#include<vector>

using namespace std;

bool isValidSudoku(vector<vector<char>> &board){
    bool rowSeen[9][9] = {false};
    bool colSeen[9][9] = {false};
    bool gridSeen[9][9] = {false};

    for(int row = 0; row < board.size(); row++){
        for(int col = 0; col < board[row].size(); col++){
            // inside cell 
            char digit = board[row][col];   

            if(digit == '.') continue;

            int digitIndex = digit - '1';

            int grid = (row / 3) * 3 + (col / 3);

            if(rowSeen[row][digitIndex] || colSeen[col][digitIndex] || gridSeen[grid][digitIndex]){
                return false;
            }
            // digit present
            rowSeen[row][digitIndex] = true;
            colSeen[col][digitIndex] = true;
            gridSeen[grid][digitIndex] = true;

        }
    }
    return true;

}

int main(){

    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'},
    };

    cout << isValidSudoku(board) << endl;
    return 0;
}