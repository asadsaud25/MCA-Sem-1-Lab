#include <iostream>
#include <cmath>
using namespace std;

int main() {
	
	int a, b, c;
	cout << "Enter values of a, b, c: " << endl;
	cin >> a >> b >> c;
	float root1 = (-b + sqrt( (b*b) -4*a*c )) / 2*a;
	float root2 = (-b - sqrt( (b*b) -4*a*c )) / 2*a;
	cout << "Roots are :\nx1 = " << root1 << "\nx2 = " << root2;
	return 0;
}
