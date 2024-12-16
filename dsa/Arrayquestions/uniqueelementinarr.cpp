// find unique elements in an array where all element occurs k times except one
#include <iostream>
#include <algorithm>
using namespace std;
void uniqueelement(int arr[], int n)
{
    int maxcount = 0;
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
            }
        }
        if (count > maxcount)
        {
            maxcount = count;
            cout << "every other element occurs " << maxcount << " times except "; // did this to print both numbers of even array
        }
        if (maxcount != count)
        {
            
            cout<<arr[i]<<" ";
           
            
        }
    }
  //  cout << "no unique element " << endl;
   // return 0;
}
void printarr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
    int uniqueelement2(int arr[], int n){
            int ans=0;
            for(int i=0;i<n;i++){
                
                ans = ans^arr[i];
               
            }

            
            return ans;

    }

int main()
{
 //   cout<<"array with one number to find "<<endl;
    int arr[] = {1, 2, 1, 5, 1, 2, 2,2,1};
   /* cout << "this is your array " << endl;
    printarr(arr, 7);
    sort(arr, arr + 7);
    cout << "this is your sorted array " << endl;
    printarr(arr, 7);
     uniqueelement(arr, 7);
     cout<<endl;
     cout<<"array with two numbers to find "<<endl;
       int arr1[4]={1,2,1,3};
    sort(arr1,arr1+4);
    printarr(arr1,4);
   uniqueelement(arr1,4);*/
   cout<<"another way to do this solution "<<endl;
   // we'll use properties of XOR
 cout<<"this is the unique element "<<  uniqueelement2(arr,9);

    return 0;
}