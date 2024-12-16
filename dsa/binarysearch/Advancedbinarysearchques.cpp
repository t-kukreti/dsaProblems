#include <iostream>
#include <algorithm>
using namespace std;

bool is_possible_solution(int arr[], int n, int m, int mid)
{
    int studentcount = 1;
    int pagesum = 0;
    for (int i = 0; i < n; i++)
    {
        if ((pagesum + arr[i]) <= mid)
        {
            pagesum += arr[i];
        }
        else
        {
            studentcount++;
            if (studentcount > m || arr[i] > mid)
            {
                return false;
            }
            pagesum = arr[i];
        }
    }
    return true;
}

int minimum_amongthe_maximum_numofpages(int arr[], int n, int m)
{

    int s = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    int ans = -1;
    int e = sum;
    int mid = s + (e - s) / 2;
    while (s <= e)
    {

        if (is_possible_solution(arr, n, m, mid))
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

bool possible_solution(int arr1[], int n, int k, int mid); // Forward declaration

int minimum_time_to_paint_the_board(int arr1[], int n, int k)
{
    int s = 0;
    int sum = 0;
    int ans = -1;
    for (int i = 0; i < n; i++)
    {
        sum += arr1[i];
    }
    int e = sum;
    int mid = s + (e - s) / 2;
    while (s <= e)
    {
        if (possible_solution(arr1, n, k, mid) == true)
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

bool possible_solution(int arr1[], int n, int k, int mid)
{
    int painter_count = 1;
    int board_sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (board_sum + arr1[i] <= mid)
        {
            board_sum += arr1[i];
        }
        else
        {
            painter_count++;
            if (painter_count > k || arr1[i] > mid)
            {
                return false;
            }
            board_sum = arr1[i];
        }
    }
    return true;
}

bool is_possible_ans(int arr[],int n,int a,int mid){
    int cow_counter = 1;
    int last_position = arr[0];
    for(int i = 0;i<n;i++){
        if(arr[i]-last_position >= mid){
            cow_counter ++;
            if(cow_counter == a){
                return true;
            }
            last_position = arr[i];
        }
        
    }
    return false;

}


int largest_min_distance_to_put_cows(int arr[],int n,int a){
    sort(arr,arr+n);
     int maxi = 0 ;
    for(int i = 0 ; i<n ; i++){
          maxi = max(arr[i],maxi);
        
    }
    int mini = maxi ;
    for(int i = 0 ; i<n ; i++){
          mini = min(arr[i],mini);
        
    }
    int e = (maxi - mini );
    int s = 0;
    int mid = s + (e-s)/2;
    int ans = -1;
    while(s<=e){
        if(is_possible_ans(arr,n,a,mid)){
                ans = mid;
                s = mid + 1;
        }
        else {
            e = mid - 1;
        }
        mid = s + (e-s)/2;
    }
    
    return ans;
}

int main()
{
    // BOOK ALLOCATION PROBLEM
    /* int arr[]={10,20,30,40};
      int n=sizeof(arr)/sizeof(arr[0]);
      int m;
      cout<<"Enter number of students "<<endl;
      cin>>m;
      cout<< "The minimum number of pages among the maximum number of pages alloted to the student is "
                  << minimum_amongthe_maximum_numofpages(arr,n,m)<<endl;
  */
    // PAINTER'S PARTITION PROBLEM
    // This was a homework

    /* int arr1[] = {2,1,5,6,2,3};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int k;
    cout << "Enter number of painters " << endl;
    cin >> k;
    cout << "Minimum time taken by " << k  
    << " painters to paint the board is " << minimum_time_to_paint_the_board(arr1, n, k) << " units " <<endl;
    */
// AGGRESSIVE COWS PROBLEM 
    int arr[] = {4,2,1,3,6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int a;
    cout<<"Enter the number of cows "<<endl;
    cin>>a;
    cout << "Largest minimum distance in which " << a <<" cow can be placed is " 
       << largest_min_distance_to_put_cows(arr,n,a)<< " units " <<endl;
    return 0;
}