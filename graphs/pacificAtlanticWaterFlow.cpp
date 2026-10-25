#include<iostream>
#include<vector>

using namespace std;

void exploreCell(vector<vector<int>> &heights, int row, int col, vector<vector<int>> &visitedMatrix){
    if(row < 0 || row >= heights.size() || col < 0 || col >= heights[0].size()) return ;

    if(visitedMatrix[row][col] == 1) return ;

    visitedMatrix[row][col] = 1;

    // up
    if(row-1 >= 0 && heights[row][col] <= heights[row-1][col] && visitedMatrix[row-1][col] != 1){
        exploreCell(heights, row-1, col, visitedMatrix);
    }
    // down
    if(row+1 < heights.size() && heights[row][col] <= heights[row+1][col] && visitedMatrix[row+1][col] != 1){
        exploreCell(heights, row+1, col, visitedMatrix);
    }
    // left 
    if(col - 1 >= 0 && heights[row][col] <= heights[row][col-1] && visitedMatrix[row][col-1] != 1){
        exploreCell(heights, row, col-1, visitedMatrix);
    }
    // right
    if(col + 1 < heights[0].size() && heights[row][col] <= heights[row][col+1] && visitedMatrix[row][col+1] != 1){
        exploreCell(heights, row, col+1, visitedMatrix);
    }
    
}
vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights){
    vector<vector<int>> visitedPacific(heights.size(), vector<int>(heights[0].size(),0));
    vector<vector<int>> visitedAtlantic(heights.size(), vector<int>(heights[0].size(),0));
    vector<vector<int>> ans;

    for(int row = 0; row < heights.size(); row ++){
        for(int col = 0; col < heights[row].size(); col ++){
            // top row or left col
            if(row == 0 || col == 0) exploreCell(heights, row, col, visitedPacific);
            if(row == heights.size()-1 || col == heights[0].size()-1) exploreCell(heights, row, col, visitedAtlantic);
        }
    }
    for(int row = 0; row < heights.size(); row ++){
        for(int col = 0; col < heights[row].size(); col ++){
            if(visitedAtlantic[row][col] && visitedPacific[row][col]){
                ans.push_back({row,col});
            }
        }
    }

    return ans;

}

void printVector(vector<vector<int>> &v){
    for(int row=0; row<v.size(); row++){
        for(int col=0; col<v[row].size(); col++){
            cout << v[row][col];
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
   vector<vector<int>> heights = {
       {1,2,2,3,5},
       {3,2,3,4,4},
       {2,4,5,3,1},
       {6,7,1,4,5},
       {5,1,1,2,4}
   }; 
   vector<vector<int>> res = pacificAtlantic(heights);
   printVector(res);

    return 0;
}
