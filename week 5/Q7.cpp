#include <iostream>
using namespace std;

int main() {
    int n, positive = 0, negative = 0, odd = 0, even = 0;
    

    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "\nPositive numbers: ";
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            cout << arr[i] << " ";
            positive++;
        }
    }
    cout << "\nCount = " << positive;

    cout << "\n\nNegative numbers: ";
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            cout << arr[i] << " ";
            negative++;
        }
    }
    cout << "\nCount = " << negative;

    cout << "\n\nOdd numbers: ";
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 != 0 && arr[i] > 0) {
            cout << arr[i] << " ";
            odd++;
        }
    }
    cout << "\nCount = " << odd;

    cout << "\n\nEven numbers: ";
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0 && arr[i] > 0) {
            cout << arr[i] << " ";
            even++;
        }
    }
    cout << "\nCount = " << even;

    return 0;
}

