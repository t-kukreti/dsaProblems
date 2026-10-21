#include<iostream>
#include<vector>

using namespace std;

void exploreAndMarkSafe(vector<vector<char>> &board, int row, int col){
    if(row < 0 || row >= board.size() || col < 0 || col >= board[0].size()) return ;

    if(board[row][col] != 'O') return ;

    // mark the cell safe
    board[row][col] = '#';
    
    exploreAndMarkSafe(board, row-1, col);
    exploreAndMarkSafe(board, row+1, col);
    exploreAndMarkSafe(board, row, col-1);
    exploreAndMarkSafe(board, row, col+1);

}

void solve(vector<vector<char>> &board){
    
    for(int row = 0; row < board.size(); row++){
        for(int col = 0; col < board[0].size(); col++){
            // found O in the boundary
            if( ((row == 0) || (row == board.size()-1) || (col == 0) || (col == board[0].size()-1)) && board[row][col] == 'O'){
                exploreAndMarkSafe(board, row, col);

            }
        }
    }
    // traverse and mark the unsafe ones 'X' and '#' ones back to 'O'
    for(int row = 0; row < board.size(); row++){
        for(int col = 0; col < board[0].size(); col++){
            if(board[row][col] == '#') board[row][col] = 'O';
            else{
                if(board[row][col] == 'O') board[row][col] = 'X';
            }
            
        }
    }
}
void printVector(vector<vector<char>> &v){
    for(int row = 0; row < v.size(); row ++){
        for(int col = 0; col < v[row].size(); col ++){
            cout << v[row][col];
        }
        cout << endl;
    }
    cout << endl;
}
int main(){
    vector<vector<char>> board = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}
    };
    cout << "before solving: " << endl;
    printVector(board);
    solve(board);
    cout << "after solving: " << endl;
    printVector(board);

    return 0;
}
