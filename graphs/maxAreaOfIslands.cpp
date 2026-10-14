#include<iostream>
#include<vector>

using namespace std;
int exploreCell(vector<vector<int>> &grid, int row, int col){
    if( row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() ) return 0;
    int count = 0;

    if( grid[row][col] == 1 ){
        grid[row][col] = -1;
        count ++;
    }else{
        return 0;
    }

    count += exploreCell(grid, row-1, col);
    count += exploreCell(grid, row+1, col);
    count += exploreCell(grid, row, col-1);
    count += exploreCell(grid, row, col+1);

    return count;

}
int maxAreaOfIsland(vector<vector<int>> &grid){
    int maxArea = 0;
    for(int row = 0; row < grid.size(); row++){
        for(int col = 0; col < grid[row].size(); col++){
            if(grid[row][col] == 1){
                int count = exploreCell(grid, row, col);
                if(count > maxArea) maxArea = count;
            }
        }
    }
    return maxArea;

}
int main(){
    vector<vector<int>> grid = {
        {0,0,1,0,0,0,0,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,1,1,0,1,0,0,0,0,0,0,0,0},
        {0,1,0,0,1,1,0,0,1,0,1,0,0},
        {0,1,0,0,1,1,0,0,1,1,1,0,0},
        {0,0,0,0,0,0,0,0,0,0,1,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,0,0,0,0,0,0,1,1,0,0,0,0}
    };
    cout << maxAreaOfIsland(grid) << endl;
    return 0;
}
