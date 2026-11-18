#include <iostream>
using namespace std;

int main() {
    int n, choice;

    cout << "Enter a 4-digit integer: ";
    cin >> n;

    if (n < 1000 || n > 9999) {
        cout << "The number is not a 4-digit integer" << endl;
        return 0;
    }

    int d1 = n / 1000;
    int d2 = (n / 100) % 10;
    int d3 = (n / 10) % 10;
    int d4 = n % 10;
    int rev = d4 * 1000 + d3 * 100 + d2 * 10 + d1;

    do {
        cout << endl;
        cout << "1. Reverse of the number" << endl;
        cout << "2. Sum of the number with its reverse" << endl;
        cout << "3. Sum of alternate digits" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Reverse: " << rev << endl;
            break;
        case 2:
            cout << "Sum with reverse: " << n + rev << endl;
            break;
        case 3:
            cout << "1st digit + 3rd digit: " << d1 + d3 << endl;
            cout << "2nd digit + 4th digit: " << d2 + d4 << endl;
            break;
        case 4:
            break;
        default:
            cout << "Invalid choice" << endl;
        }
    } while (choice != 4);

    return 0;
}
