#include <iostream>
#include <string>
using namespace std;

int main()
{
    string S, T;

    cout << "Enter string S: ";    
    getline(cin, S);

    cout << "Enter string T: ";
    getline(cin, T);

    size_t pos = S.find(T);

    if (pos != string::npos)
        cout << "T begins at index: " << pos << endl;
    else
        cout << "1" << endl;

    return 0;
}

