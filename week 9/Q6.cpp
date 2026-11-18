#include <iostream>
using namespace std;

int sum(int arr[], int n)
{
    if (n == 0)
        return 0;

    return arr[n - 1] + sum(arr, n - 1);
}

int main()
{
    int arr[100], n, result;

    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter array elements:\n";

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    result = sum(arr, n);

    cout << "Sum of array elements = " << result;

    return 0;
}

