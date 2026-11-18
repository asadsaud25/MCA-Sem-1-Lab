
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    string sentence, word, currentWord;
    int count = 0;

    cout << "Enter a line of text: ";
    getline(cin, sentence);

    cout << "Enter the word to count: ";
    cin >> word;

    stringstream ss(sentence);

    while (ss >> currentWord)
    {
        if (currentWord == word)
            count++;
    }

    cout << "The word '" << word << "' occurs " << count << " times." << endl;

    return 0;
}

