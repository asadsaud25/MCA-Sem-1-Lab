#include <iostream>
using namespace std;

int main() {
    int n, num, target, frequency = 0;

    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter the integers: ";
    for (int i = 0; i < n; i++) {
        cin >> num;
    }

    cout << "Enter the number to find: ";
    cin >> target;
    
    cout << "Enter the integers: ";
    for (int i = 0; i < n; i++) {
        if (num == target) {
            frequency++;
        }
    }

    cout << "Frequency of " << target << " = " << frequency << endl;

    return 0;
}

