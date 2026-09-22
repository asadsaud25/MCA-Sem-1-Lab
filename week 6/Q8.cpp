#include <iostream>
using namespace std;

int main() {
    int n, sum = 0;
    int arr[100];
    int *ptr;

    cout << "Enter the number of elements: ";
    cin >> n;

    ptr = arr;
    
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> *(ptr + i);
    }

    for (int i = 0; i < n; i++) {
        sum = sum + *(ptr + i);
    }

    cout << "Sum = " << sum << endl;

    return 0;
}

