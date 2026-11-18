#include <iostream>
#include <string>
using namespace std;

void insertSubstring(string &str, string sub, int pos)
{
    str.insert(pos, sub);
    cout << "String after insertion: " << str << endl;
}

void deleteCharacters(string &str, int pos, int n)
{
    str.erase(pos, n);
    cout << "String after deletion: " << str << endl;
}

int main()
{
    string str, sub;
    int pos, n;

    cout << "Enter the main string: ";
    getline(cin, str);

    cout << "Enter the substring to insert: ";
    getline(cin, sub);

    cout << "Enter the position for insertion (0-based): ";
    cin >> pos;

    if (pos >= 0 && pos <= (int)str.length())
        insertSubstring(str, sub, pos);
    else
        cout << "Invalid insertion position!" << endl;

    cout << "\nEnter the position for deletion (0-based): ";
    cin >> pos;

    cout << "Enter the number of characters to delete: ";
    cin >> n;

    if (pos >= 0 && pos <= (int)str.length() && n >= 0)
        deleteCharacters(str, pos, n);
    else
        cout << "Invalid position or number of characters!" << endl;

    return 0;
}
