#include <iostream>
using namespace std;

int main() {
    int n, target, frequency = 0;
    cout << "Enter the number of elements: ";
    cin >> n;
	int num[n];
    cout << "Enter the integers: ";
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    cout << "Enter the number to find: ";
    cin >> target;
    
    cout << "Enter the integers: ";
    for (int i = 0; i < n; i++) {
        if (num[i] == target) {
            frequency++;
        }
    }

    cout << "Frequency of " << target << " = " << frequency << endl;

    return 0;
}

