#include <iostream>
using namespace std;
int getpivot(int arr[], int n)
{
    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;
    while (s < e)
    {
        if (arr[mid] >= arr[0])
        {
            s = mid + 1;
        }
        else
        {
            e = mid;
        }
        mid = s + (e - s) / 2;
    }
    return s;
}
int binarysearch(int arr[], int s, int e, int key)
{
    s = s;
    e = e;
    int m = s + (e - s) / 2; // dont use this (start+end)/2;

    while (s <= e)
    {
        if (arr[m] == key)
        {
            return m;
        }
        // Go to right
        if (key > arr[m])
        {
            s = m + 1;
        }
        else
        { // key<arr[mid]
            e = m - 1;
        }

        m = s + (e - s) / 2; // mid=(start+end)/2;
    }
    cout << "Key is absent " << endl;
    return -1;
}
int findposition(int arr[], int n, int key)
{
    int pivot = getpivot(arr, n);
    if (key >= arr[pivot] && key <= arr[n - 1])
    {

        return binarysearch(arr, pivot, n - 1, key);
    }
    else
    {

        return binarysearch(arr, 0, pivot - 1, key);
    }

    return 0;
}
int main()
{
    int arr[] = {7, 9, 1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key;
    cout << "Enter your key " << endl;
    cin >> key;
    cout << "Pivot is " << getpivot(arr, n) << endl;
    cout << key << " is present at index " << findposition(arr, n, key) << endl;
    return 0;
}