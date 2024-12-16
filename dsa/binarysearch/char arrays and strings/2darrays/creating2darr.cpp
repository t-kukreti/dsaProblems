#include<iostream>
using namespace std;
int linearsearch(int arr[][4] , int key){
    for(int row = 0; row < 3 ; row ++){
        for(int col = 0; col < 4 ; col ++){
            
            if(arr[row][col] == key ){
                    cout<<"key is present " <<endl;
                    return 1;
            }
        }
    }
    cout<<"Key is not present " <<endl;
return 0;
}

void print2darray(int arr[][4]){
    for(int row = 0 ; row < 3 ; row ++){
        for(int col = 0 ; col < 4 ; col ++){
            cout<<arr[row][col]<<" ";
        }
        cout<<endl;
    }
}
void get2darray(int arr[][4]){
    for(int row = 0 ; row < 3 ; row ++){
        for(int col = 0 ; col < 4 ; col ++){
            cin>>arr[row][col];
        }
    }
}
void row_wise_sum(int arr[][4] ){
    for(int row = 0 ; row < 3 ; row ++){
        int sum = 0;
        for(int col = 0 ; col < 4 ; col ++){
            sum += arr[row][col];
        }
        cout<<"Row " <<row <<" sum is : " << sum <<endl;
        
    }
    cout<<endl;
}
void column_wise_sum(int arr[][4] ){
    for(int col = 0 ; col < 4 ; col ++){
        int sum = 0;
        for(int row = 0 ; row < 3 ; row ++){
            sum += arr[row][col];
        }
        cout<<"col " <<col <<" sum is : " << sum <<endl;
        
    }
    cout<<endl;
}
int largest_row_sum(int arr[][4]){
    int maxi = -1;
    int row_number = -1;
    for(int row = 0 ; row < 3 ; row ++){
        int sum = 0;
        for(int col = 0 ; col < 4 ; col ++){
            sum += arr[row][col];
        }
        if(sum>maxi){
            maxi = sum ;
            row_number = row;
        }
    }
    cout<<"The maximum sum is " << maxi <<endl;
    cout<<"Row with the largest sum is : " ;
    return row_number;
}
int main(){
   // int row ,  col ;
    int arr[3][4] = {1,2,3,4,5,6,7,8,9,1,2,3};
    int key = 8 ;
   // cout<<"Enter key " <<endl;
    //cin>>key;
    cout<<"Enter array elements " <<endl;
  // get2darray(arr);
   print2darray(arr);
   row_wise_sum(arr);
   column_wise_sum(arr);
   cout<<largest_row_sum(arr);
   cout<<endl;
   cout<<linearsearch(arr,key);
    return 0;
}