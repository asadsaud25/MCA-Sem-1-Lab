#include <iostream>
#include <string>
using namespace std;

class Student {
    string name;
    string branch;
    string year;

public:
    Student(string n, string b, string y) {
        name = n;
        branch = b;
        year = y;
    }

    void display() {
        cout << "Name: " << name << endl;
        cout << "Branch: " << branch << endl;
        cout << "Year: " << year << endl;
    }
};

int main() {
    string name, branch, year;

    cout << "Enter name: ";
    getline(cin, name);
    cout << "Enter branch: ";
    getline(cin, branch);
    cout << "Enter year: ";
    getline(cin, year);

    Student s(name, branch, year);
    cout << endl;
    s.display();
    return 0;
}
