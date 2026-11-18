#include <iostream>
using namespace std;

int findMax(int arr[], int n)
{
    if (n == 1)
        return arr[0];

    int max = findMax(arr, n - 1);

    if (arr[n - 1] > max)
        return arr[n - 1];
    else
        return max;
}

int findMin(int arr[], int n)
{
    if (n == 1)
        return arr[0];

    int min = findMin(arr, n - 1);

    if (arr[n - 1] < min)
        return arr[n - 1];
    else
        return min;
}

int main()
{
    int arr[100], n;

    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter array elements:\n";

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Maximum element = " << findMax(arr, n) << endl;
    cout << "Minimum element = " << findMin(arr, n) << endl;

    return 0;
}

