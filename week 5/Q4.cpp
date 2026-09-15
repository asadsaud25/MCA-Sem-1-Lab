#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int largest = INT_MIN;
    int second = INT_MIN;

    cout << "Enter the integers:\n";

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        if (x > largest) {
            second = largest;
            largest = x;
        } else if (x > second && x != largest) {
            second = x;
        }
    }

    if (second == INT_MIN) {
        cout << "There is no second-largest distinct integer." << endl;
    } else {
        cout << "Second-largest integer: " << second << endl;
    }

    return 0;
}

