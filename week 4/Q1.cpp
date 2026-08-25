#include <iostream>
using namespace std;

int main() {
	int num;
	cout << "Enter number: " << endl;
	cin >> num;
	string result = ((num % 2) == 0) ? "Even":"Odd";
	cout << "The given number is " << result << endl;
	return 0;
}
