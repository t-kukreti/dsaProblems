#include <iostream>
#include <algorithm>
using namespace std;
void printarr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void tripletsum(int arr[], int n, int sum)
{
    for (int i = 0; i < n; i++)
    {
        cout << "step " << i << endl;
        for (int j = i + 1; j < n; j++)
        {
            cout << "step " << j << endl;

            for (int k = j + 1; k < n; k++)

            {
                cout << "step " << k << endl;
                if (arr[i] + arr[j] + arr[k] == sum)
                {
                    cout << arr[i] << " + " << arr[j] << " + " << arr[k] << " = " << sum << endl;
                }
                /*else if(arr[i]+arr[j]+arr[k]<sum){
                    cout<<arr[i] <<" + " <<arr[j] <<" + " <<arr[k] <<" < " <<sum<<endl;

                }*/
                else if (arr[i] + arr[j] + arr[k] > sum)
                {
                    // cout<<arr[i] <<" + " <<arr[j] <<" + " <<arr[k] <<" > " <<sum<<endl;

                    break;
                }
            }
        }
    }
}

int main()
{

    int arr[] = {1, 4, 45, 8, 10};
    int sum = 13;
    sort(arr, arr + 5);
    printarr(arr, 5);
    tripletsum(arr, 5, sum);

    return 0;
}