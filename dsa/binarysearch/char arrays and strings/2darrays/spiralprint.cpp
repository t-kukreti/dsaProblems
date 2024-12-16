#include<iostream>
#include<vector>
using namespace std;
void printarr(int arr[][3]){
    for(int i = 0 ;i<3; i++){
        for(int j=0;j<3;j++){
                cout<<arr[i][j]<<" ";
        }
    cout<<endl;
    }
}
void printarr(vector<int> n){
    for(int i=0;i<n.size();i++){
        cout<<n[i]<<" ";
    }
    cout<<endl;
}
vector<int> spiralprint(int arr[][3],int row, int col){
    vector<int> ans;
   int count = 0;
   int total_element = row * col;
    // indexes
    int starting_row = 0 ;
    int starting_col = 0;
    int ending_row = row - 1;
    int ending_col = col -1;

    while(count<total_element){
        for(int index = starting_col ; count<total_element&& index <= ending_col ; index ++){
                ans.push_back(arr[starting_row][index]);
                count ++;
        }
        starting_row ++;
        for(int index = starting_row ; count<total_element&& index <= ending_row ; index ++){
                ans.push_back(arr[index][ending_col]);
                count ++;
        }
        ending_col --;
        for(int index = ending_col ; count<total_element&& index >= starting_col ; index --){
                ans.push_back(arr[ending_row][index]);
                count ++;
        }
        ending_row --;
        for(int index = ending_row ; count<total_element&& index >= starting_row ; index --){
                ans.push_back(arr[index][starting_col]);
                count ++;
        }
        starting_col ++;

    }
   // printarr(ans);
    return ans;
}

int main(){
    int arr[3][3] = {1,2,3,4,5,6,7,8,9};
    printarr(arr);
    cout<<"This is your spiral printed array " <<endl;
    printarr(spiralprint(arr,3,3));
    return 0;
}