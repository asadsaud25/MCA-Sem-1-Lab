#include <iostream>
#include <string>
using namespace std;

int main()
{
    string sentence, oldStr, newStr, result;

    cout << "Enter a sentence: ";
    getline(cin, sentence);

    cout << "Enter the string to find: ";
    getline(cin, oldStr);

    cout << "Enter the replacement string: ";
    getline(cin, newStr);

    int i = 0;

    if (oldStr.empty())
    {
        cout << "Search string cannot be empty." << endl;
        return 0;
    }

    while (i < sentence.length())
    {
        int j = 0;

        while (j < oldStr.length() && 
               i + j < sentence.length() &&
               sentence[i + j] == oldStr[j])
        {
            j++;
        }

        if (j == oldStr.length())
        {
            result += newStr;
            i += j;
        }
        else
        {
            result += sentence[i];
            i++;
        }
    }

    cout << "After replacement: " << result << endl;

    return 0;
}
