#include <iostream>
using namespace std;

int main()
{
    string str;
    
    cout << "Enter a string: ";
    getline(cin, str);

    string *ptr = &str;

    cout << "String: " << *ptr;

    return 0;
}

