#include<iostream>
#include<vector>
using namespace std;

void print2dvector(vector<vector<int>> arr){
    for(int i = 0 ; i< arr.size() ; i++){
        for(int j = 0 ; j< arr[i].size() ; j++){
            cout<<arr[i][j] <<" ";
        }
        cout<<endl;
    }
}
/*void printvector(vector<int>v){
    for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j < 3 ; j++){
            cout<<v[i];
            cout<<v[j];
            cout<<" ";
        }
    cout<<endl;
    }
}*/
vector<int> wave_print (vector<vector<int>> arr , int nrows , int mcols){
    vector<int>ans;
    for(int col = 0 ; col < mcols ; col ++){
        if(col & 1 ) {
            // Odd index -> Bottom to top
            for(int row = nrows-1 ; row>=0 ; row--){
                cout<<arr[row][col]<<" ";
                ans.push_back(arr[row][col]);
            }
        }
        else {
            // 0 or Even index -> Top to bottom
            for(int row = 0 ; row < nrows ; row++){
                cout<<arr[row][col]<<" ";
                ans.push_back(arr[row][col]);
            }
        }
    }
    //printvector(ans);
    return ans;
   
}
    

int main(){
    vector<vector<int>> arr 
    {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    //int arr[3][3]= {1,2,3,4,5,6,7,8,9};
    cout<<"This is your array " <<endl;
    wave_print(arr,3,3);
  //  print2dvector(arr);
   // print2darray(arr);
    return 0;
}