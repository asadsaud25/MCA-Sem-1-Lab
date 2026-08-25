#include <iostream>
using namespace std;

int main() {
	int a, b, c, d, e, f, g;
	cout << "Enter value of a: " << endl;
	cin >> a;
	cout << "Enter value of b: " << endl;
	cin >> b;
	cout << "Enter value of c: " << endl;
	cin >> c;
	cout << "Enter value of d: " << endl;
	cin >> d;
	cout << "Enter value of e: " << endl;
	cin >> e;
	cout << "Enter value of f: " << endl;
	cin >> f;
	cout << "Enter value of g: " << endl;
	cin >> g;
	float exp = (a+b/c*d-e)*(f-g);
	cout << "Value of given expression: " << exp << endl;
	return 0;
}
