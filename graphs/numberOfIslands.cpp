#include<iostream>
#include<vector>

using namespace std;

void exploreCell(vector<vector<char>> &grid, int row, int col){

   // at edges row / col can be negative, valid boundary check
   if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size()) return;
   // mark cell visited
   if(grid[row][col] == '1'){
       grid[row][col] = '#';
   }else{
       return ;
   } 
   // move left
   exploreCell(grid, row, col-1);
   // move right
   exploreCell(grid, row, col+1);
   // move down
   exploreCell(grid, row+1, col);
   // move top
   exploreCell(grid, row-1, col);

}
int numIslands(vector<vector<char>> &grid){
    int islandCount = 0;
    for(int row=0; row<grid.size(); row++){
        for(int col=0; col<grid[row].size(); col++){
            if(grid[row][col] == '1'){
                islandCount ++;
                exploreCell(grid, row, col);
            }
        }
    }
return islandCount;

}
int main(){
    vector<vector<char>> grid = {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
    };

    cout << numIslands(grid) << endl;

    return 0;
}
