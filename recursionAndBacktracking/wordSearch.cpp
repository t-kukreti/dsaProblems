#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool solve(vector<vector<char>> &board, string word, int row, int col, int index) {
    // base conditions
    // word matched 
    if(word.length() == index){
        return true;
    }
    // invalid path
    if(row < 0 || row >= board.size() || col < 0 || col >= board[row].size()){
        return false;
    }
    // reusing cell
    if(board[row][col] == '#'){
        return false;
    }
    // current cell doesn't match next matching letter
    if(board[row][col] != word[index]){
        return false;
    }

    // the word matches, mark the board
    char markedLetter = board[row][col];
    board[row][col] = '#';

    // explore choices up, down, right, left
    if(
        // up
        solve(board, word, (row-1), col, (index+1)) || 
        // down
        solve(board, word, (row+1), col, (index+1)) || 
        // right
        solve(board, word, row, (col+1), (index+1)) || 
        // left
        solve(board, word, row, (col-1), (index+1)) 
    ) {
        board[row][col] = markedLetter;
        return true;
    }
    else{
        // path invalid
        board[row][col] = markedLetter;
        return false;
    }
}
bool exist(vector<vector<char>> &board, string word) {
    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board[i].size(); j++){
            if(board[i][j] == word[0]){
                if(solve(board, word, i, j, 0)) return true;
            }
        }
    }
    return false;
}

int main() {
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'},
    };
    string word = "ABCCED";

    cout << exist(board, word) << endl;
    return 0;
}