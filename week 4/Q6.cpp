#include <iostream>
using namespace std;

int main() {
	char c;
	cout << "Enter Character: ";
	cin >> c;
	if (c > 65 && c < 90) cout << "Character is a Capital Letter";
	else if (c > 97 && c < 122)  cout << "Character is a Small Letter";
	else if (c > 48 && c < 57) cout << "Character is Digit";
	else cout << "Character is a Special Character";
}

