#include<iostream>
#include<vector>
using namespace std;

bool search_matrix(vector<vector<int>> &v , int target){
    int row = v.size();
    int col = v[0].size();
    int rowindex = 0;
    int colindex = col - 1;

    while(rowindex<row && colindex >= 0 ){
        int element = v[rowindex][colindex];
        if(element == target){
            return 1;
        }
        else if(target > element ){
            rowindex ++;
        }
        else{  // element > target
            colindex --;
        }
    }


    return 0;
}

int main(){
    vector<vector<int>> matrix 
    {
        {1,4,7,11,15},
        {2,5,8,12,19},
        {3,6,9,16,22},
        {10,13,14,17,24},
        {3,6,9,16,22}
    };
    int target = 17;
    if(search_matrix(matrix , target)){
        cout<<"True " <<endl;
    }
    else{
        cout<<"False " <<endl;
    }

    
    return 0;
}