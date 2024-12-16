#include <iostream>
#include <vector>
using namespace std;
void printarr(vector<vector<int>> n)
{
  for (int i = 0; i < n.size(); i++)
  {
    for (int j = 0; j < n[0].size(); j++)
    {
      cout << n[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}
void rotate(vector<vector<int>> &matrix)
{
  int row = matrix.size();
  int col = matrix[0].size();
  for (int i = 0; i < row ; i++)
  {
    for (int j = i+1; j < col; j++)
    {
      swap(matrix[i][j], matrix[j][i]);
    }
  }
  int x = col - 1 , j = 0 ;
  while(j<=x){
  for(int i = 0 ; i< row ; i++){
    swap(matrix[i][j] , matrix[i][x]);
  }
  j++ , x--;
  }
}

int main()
{
  vector<vector<int>> matrix = {
      {5,1,9,11},
      {2,4,8,10},
      {13,3,6,7},
      {15,14,12,16}
      };
  cout << "Before rotating " << endl;
  printarr(matrix);
  rotate(matrix);
  cout << "After rotating " << endl;
  printarr(matrix);

  return 0;
}