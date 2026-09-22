#include <iostream>
using namespace std;

int main() {
    char str1[200], str2[100];
    char *p1, *p2;

    cout << "Enter first string: ";
    cin.getline(str1, 100);

    cout << "Enter second string: ";
    cin.getline(str2, 100);

    p1 = str1;
    p2 = str2;

    while (*p1 != '\0') {
        p1++;
    }
    while (*p2 != '\0') {
        *p1 = *p2;
        p1++;
        p2++;
    }
    *p1 = '\0';
    cout << "Concatenated string = " << str1 << endl;

    return 0;
}

