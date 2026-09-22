#include <iostream>
using namespace std;

int main() {
    int arr[5];
    int *ptr;

    ptr = arr;

    cout << "Enter 5 elements: ";
    for (int i = 0; i < 5; i++) {
        cin >> *(ptr + i);
    }

    cout << "Array elements are: ";
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}

