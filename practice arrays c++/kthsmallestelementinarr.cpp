#include <iostream>
using namespace std;

void printarr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void selectionsort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {

        int minindex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minindex])
            {
                minindex = j;
            }
        }
        int key = arr[minindex];

        while (minindex > i)
        {
            arr[minindex] = arr[minindex - 1];

            minindex--;
        }
        arr[i] = key;
    }
}

int main()
{
    int arr[] = {7, 10, 4, 3, 20, 15}; // 3 4 7 10 15 20
    int n = sizeof(arr) / sizeof(arr[0]);

    selectionsort(arr, n);
    cout << "This is your sorted array " << endl;
    printarr(arr, n);
    int k;
    cout << "which smallest element (given that it should be less than the size of the array) " << endl;
    cin >> k;

    if (k > n)
    {
        cout << "Can't you read? " <<endl 
        <<"now read the given condition properly " << endl;
        return -1;
    }
    cout << "The " << k << "th smallest element is " << arr[k - 1] << endl;
    cout << "The " << k << "th largest element is " << arr[n - k] << endl;
    return 0;
}