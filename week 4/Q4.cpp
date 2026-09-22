#include <iostream>
using namespace std;

int main() {
	int n, i, fib = 0;
	cout << "Enter Number: ";
	cin >> n;
	int a=0, b=1;
	for (i=0; i<n; i++) {
		cout << a << " ";
		int temp = a + b;
		a = b;
		b = temp;
		
	}	
	return 0;
}

