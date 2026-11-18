#include <iostream>
#include <string>
using namespace std;

struct Date {
    int day;
    int month;
    int year;
};

struct DOB {
    string name;
    Date date;
};

int main() {
    DOB d;

    cout << "Enter name: ";
    getline(cin, d.name);
    cout << "Enter day: ";
    cin >> d.date.day;
    cout << "Enter month: ";
    cin >> d.date.month;
    cout << "Enter year: ";
    cin >> d.date.year;

    cout << endl << "Name: " << d.name << endl;
    cout << "Date of Birth: " << d.date.day << "/" << d.date.month << "/" << d.date.year << endl;
    return 0;
}
