#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int target) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main() {
    int n, target;
    cout << "Enter number of elements: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid size" << endl;
        return 0;
    }

    int *arr = new int[n];
    cout << "Enter " << n << " integers in sorted (ascending) order: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter the target element: ";
    cin >> target;

    int index = binarySearch(arr, n, target);
    if (index == -1)
        cout << "Element not found" << endl;
    else
        cout << "Element found at index " << index << endl;

    delete[] arr;
    return 0;
}
