#include <iostream>
using namespace std;
int main() {
    int num;
    cout << "Enter number: " ;
    cin >> num;
    int *p = &num;
    (*p)++;
    cout << "After increment: " << *p << endl;
    (*p)--;
    (*p)--;
    cout << "After two decrements: " << *p << endl;
    return 0;
}

