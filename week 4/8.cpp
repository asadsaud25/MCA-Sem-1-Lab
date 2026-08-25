#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n,sum=0, d=0;
	cout << "Enter number: ";
	cin >> n;
	int temp = n;
	while(temp > 0) {
		d++;
		temp/=10;
	}
	
	temp = n;
	while(temp > 0) {
		sum += pow((temp%10),d);
		temp/=10;		
	}
	if (sum == n) {
		cout << "Given number is Armstrong number";
	} else {
		cout << "Given number is NOT a Armstrong number";
	}
	return 0;
}
