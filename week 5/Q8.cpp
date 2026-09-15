#include <iostream>
using namespace std;

int main() {
    int n, m;

    cout << "Enter size of first array: ";
    cin >> n;

    int A[100];
    cout << "Enter elements of first sorted array: ";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    cout << "Enter size of second array: ";
    cin >> m;

    int B[100];
    cout << "Enter elements of second sorted array: ";
    for (int i = 0; i < m; i++) {
        cin >> B[i];
    }

    int C[200];
    int i = 0, j = 0, k = 0;

    while (i < n && j < m) {
        if (A[i] <= B[j]) {
            C[k] = A[i];
            i++;
        } else {
            C[k] = B[j];
            j++;
        }
        k++;
    }

    while (i < n) {
        C[k] = A[i];
        i++;
        k++;
    }

    while (j < m) {
        C[k] = B[j];
        j++;
        k++;
    }

    cout << "Merged sorted array: ";
    for (int i = 0; i < n + m; i++) {
        cout << C[i] << " ";
    }

    return 0;
}

