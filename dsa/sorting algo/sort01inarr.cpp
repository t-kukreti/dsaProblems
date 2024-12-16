#include<iostream>
using namespace std;
void printarr(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void sort01(int arr[],int n){
    int left = 0, right = n-1;
    while(left<right){
        cout<<"step " << left <<endl;
        printarr(arr,8);
        while(arr[left]==0 && left<right){
            left++;
        }
        while(arr[right]==1 && left<right){
            right -- ;
        }
       if(arr[left]==1 && arr[right]==0){
            swap(arr[left],arr[right]);
            left++ , right--;
        }
    }


}
/*void sort(int arr[],int n ){
    int i = 0 , j=n-1;
    while(i<j){
        cout<<"step "<< i <<endl;
        printarr(arr,8);
    if(arr[i]==0){
        i++;
    }
    if(arr[j]==1){
        j--;
    }
    else if (arr[i]==1){
        swap(arr[i],arr[j]);
       i++, j--;
    }
}
}*/
    
/*void sort012(int arr[],int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[j]<=arr[i]){
                int temp = arr[j];
                arr[j]=arr[i];
                arr[i]=temp;
            }
        }
    }   
}*/
void sort012(int arr[],int n){
    int i= 0 , j = 0 , k=n-1;
    while(j<k){
        cout<<"step " << j <<endl;
        printarr(arr,8);
        if(arr[j]==0){
            swap(arr[i],arr[j]);
            i++ , j++;
        }
        while(arr[j]==1 && j<k){
            j++;
        }
    
      if (arr[j]==2){
        swap(arr[j], arr[k]);
        k--;

    }
  
}
}
int main(){
   // int arr[] = {1,0,1,1,0,0,1,0};
    
    // printarr(arr,8);
    
  int arr[]={0 ,1, 2, 0, 1 ,1, 2, 2 };

   
    
    cout<<"This is your array "<< endl;
    printarr(arr,8);
    /*printarr(arr,6);
    sort01(arr,6);
    printarr(arr,6);*/

    sort012(arr,8);
    printarr(arr,8);
   
    return 0;
}