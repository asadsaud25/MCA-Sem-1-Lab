#include <iostream>
using namespace std;

/*
Characters ASCII values A– Z: 65– 90, a– z: 97– 122, digit: 48– 57
Special symbols 0– 47, 58– 64, 91– 96, 123– 127
*/
int main() {
	char c;
	cout << "Enter Character: ";
	cin >> c;
	if (c > 65 && c < 90) cout << "Character is a Capital Letter";
	else if (c > 97 && c < 122)  cout << "Character is a Small Letter";
	else if (c > 48 && c < 57) cout << "Character is Digit";
	else cout << "Character is a Special Character";
}
