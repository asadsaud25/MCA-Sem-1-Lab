#include <iostream>
using namespace std;

int main() {
	string s;
	cout << "Enter the string: ";
	getline(cin, s);
	
	char *p = &s[0];
	int count = 0;
	for (int i=0; i<s.size(); i++) {
		char ch = *(p+i);
		if ( ch == 'a' || ch == 'e' || ch == 'i'
			|| ch == 'o' || ch == 'u' || ch == 'A'
			|| ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U'
			) {
				count++;
			}
	}
	cout << "No. of vowels in given string: " << count;
	return 0;
}
