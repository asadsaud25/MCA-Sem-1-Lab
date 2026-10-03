#include <iostream>
using namespace std;

int main() {
	string s;
	cout << "Enter string: ";
	getline(cin,s);
	char *p = &s[0];
	int l=0;
	while (*p != '\0') {
		*(p++);
		l++;
	}
	cout << "length of string: " << l;
	return 0;
}
