#include <iostream>
using namespace std;

int main() {
    int r1, c1, r2, c2;

    cout << "Enter rows and columns of first matrix: ";
    cin >> r1 >> c1;

    cout << "Enter rows and columns of second matrix: ";
    cin >> r2 >> c2;

    int A[r1][c1], B[r2][c2], sum[r1][c1], product[r1][c2];

    cout << "Enter elements of first matrix:\n";
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            cin >> A[i][j];
        }
    }

    cout << "Enter elements of second matrix:\n";
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            cin >> B[i][j];
        }
    }

    if (r1 == r2 && c1 == c2) {
        for (int i = 0; i < r1; i++) {
            for (int j = 0; j < c1; j++) {
                sum[i][j] = A[i][j] + B[i][j];
            }
        }

        cout << "\nAddition of two matrices:\n";
        for (int i = 0; i < r1; i++) {
            for (int j = 0; j < c1; j++) {
                cout << sum[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "\nMatrix addition is not possible.\n";
        cout << "Both matrices must have the same dimensions.\n";
    }

    if (c1 == r2) {
        for (int i = 0; i < r1; i++) {
            for (int j = 0; j < c2; j++) {
                product[i][j] = 0;
            }
        }

        for (int i = 0; i < r1; i++) {
            for (int j = 0; j < c2; j++) {
                for (int k = 0; k < c1; k++) {
                    product[i][j] += A[i][k] * B[k][j];
                }
            }
        }

        cout << "\nMultiplication of two matrices:\n";
        for (int i = 0; i < r1; i++) {
            for (int j = 0; j < c2; j++) {
                cout << product[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "\nMatrix multiplication is not possible.\n";
        cout << "Columns of first matrix must equal rows of second matrix.\n";
    }

    return 0;
}

