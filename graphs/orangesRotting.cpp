#include<iostream>
#include<queue>
#include<vector>
#include<utility>

using namespace std;

int orangesRotting(vector<vector<int>>& grid){
    int freshOranges = 0;
    queue<pair<int,int>> rottenOranges;
    

    for(int row = 0; row < grid.size(); row++){
        for(int col = 0; col < grid[0].size(); col++){
            if(grid[row][col] == 2){
                rottenOranges.push({row,col});
            }
            if(grid[row][col] == 1){
                freshOranges ++;
            }

        }
    }

    // start marking oranges rotten 
    int minutes = 0;
    while(! rottenOranges.empty()){
        int rotted = false;
        // check how many rotten oranges are there
        int countOfRottenOranges = rottenOranges.size();
        for(int i=0; i<countOfRottenOranges; i++){
            // process exactly those two rotten oranges.

            pair<int, int> rottenOrange = rottenOranges.front();
            // check adjacent top down left right
            int row = rottenOrange.first, col = rottenOrange.second;

            if(col-1 >= 0 && grid[row][col-1] == 1){
                rotted = true;
                // mark it rotten
                grid[row][col-1] = 2;
                freshOranges --;
                // push it into queue
                rottenOranges.push({row, col-1});
            }
            if(col + 1 < grid[0].size() && grid[row][col+1] == 1){
                rotted = true;
                grid[row][col+1] = 2;
                freshOranges --;
                rottenOranges.push({row, col+1});

            }
            if(row + 1 < grid.size() && grid[row+1][col] == 1){
                rotted = true;
                grid[row+1][col] = 2;
                freshOranges --;
                rottenOranges.push({row+1, col});
            }
            if(row -1 >= 0 && grid[row-1][col] == 1){
                rotted = true;
                grid[row-1][col] = 2;
                freshOranges --;
                rottenOranges.push({row-1,col});
            }

            // pop the element that you just explored
            rottenOranges.pop();

        }
        // if atleast one orange rotted in the current level increment the minute.
        if(rotted) minutes ++;


    }

    if(freshOranges > 0) return -1;
    return minutes;
}

int main(){

    vector<vector<int>> grid = {
        {2,1,1},
        {1,1,0},
        {0,1,1}
    };
    cout << orangesRotting(grid) << endl;

    return 0;
}
