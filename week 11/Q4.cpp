#include <iostream>
#include <string>
using namespace std;

string convert(long long n, int base) {
    if (n == 0)
        return "0";
    const char digits[] = "0123456789ABCDEF";
    string result = "";
    while (n > 0) {
        result = digits[n % base] + result;
        n /= base;
    }
    return result;
}

int main() {
    long long n;
    int choice;

    cout << "Enter a non-negative integer: ";
    cin >> n;

    if (n < 0) {
        cout << "Negative numbers are not supported" << endl;
        return 0;
    }

    do {
        cout << endl;
        cout << "1. Binary" << endl;
        cout << "2. Octal" << endl;
        cout << "3. Hexadecimal" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Binary: " << convert(n, 2) << endl;
            break;
        case 2:
            cout << "Octal: " << convert(n, 8) << endl;
            break;
        case 3:
            cout << "Hexadecimal: " << convert(n, 16) << endl;
            break;
        case 4:
            break;
        default:
            cout << "Invalid choice" << endl;
        }
    } while (choice != 4);

    return 0;
}
