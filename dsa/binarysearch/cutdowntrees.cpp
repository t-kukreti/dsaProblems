#include <iostream>
#include <algorithm>
using namespace std;

bool is_possible_solution(int arr[], int n, int m, int mid)
{

    int sum = 0;

    int i = 0;
    while (i < n)
    {
        if (mid <= arr[i])
        {
            sum += (arr[i] - mid);
        }
        i++;
    }
    cout<<"The sum is " <<sum << " in case of " << mid <<endl;
    if (sum > m)
    {

        return false;
    }

    return true;
}
int min_height_setting(int arr[], int n, int m)
{

    sort(arr, arr + n);
    int s = arr[0];

    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        maxi = max(arr[i], maxi);
    }
    int e = maxi;
    int mid = s + (e - s) / 2;
    int ans = -1;
    while (s <= e)
    {
        if (is_possible_solution(arr, n, m, mid))
        {
            cout<<"entered bool func" <<endl;
            
            ans = mid;
            cout<<"before updating e "<<e <<endl;
            e = mid-1;
            cout<<"after updating e " <<e <<endl;
        }
        else
        {
                cout<<"before updating " << s <<endl;
            s = mid + 1;
            cout<<"after updating s "<<s <<endl;
        }

        mid = s + (e - s) / 2;
        cout<<"The mid is after calculating "<<mid <<endl;
    }
    
    return ans;
}

int main()
{
    int arr[] = {20, 15, 10, 17};
    //  int arr[]= {4, 42 ,40, 26 ,46};
    int n = sizeof(arr) / sizeof(arr[0]);
    int m;
    cout << "Enter wood required for you ";
    cin >> m;
    cout << "Minimum height required ";

    cout << min_height_setting(arr, n, m);
    return 0;
}