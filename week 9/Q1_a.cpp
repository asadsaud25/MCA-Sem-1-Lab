#include <iostream>
using namespace std;

void fact(int a) {
	int f = 1;
	for (int i=1; i<=a; i++) {
		f *= i;
	}
	cout << "Factorial without using recursion: " << f << endl;
}
 
int fact_r(int a) {
	if (a == 0 || a == 1) {
		return 1;
	}
	return a*fact_r(a-1);
}

int main() {
	fact(5);
	cout << "Factorial without using recursion: " << fact_r(5);	
	return 0;
}
