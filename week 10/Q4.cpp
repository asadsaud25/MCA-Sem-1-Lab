#include <iostream>
#include <cstring>
using namespace std;

union Address {
    char name[50];
    char home_address[100];
    char hostel_address[100];
    char city[50];
    char state[50];
    char zip[10];
};

int main() {
    Address a;

    cout << "Present Address" << endl;

    cout << "Name: ";
    cin.getline(a.name, sizeof(a.name));
    cout << a.name << endl;

    cout << "Home address: ";
    cin.getline(a.home_address, sizeof(a.home_address));
    cout << a.home_address << endl;

    cout << "Hostel address: ";
    cin.getline(a.hostel_address, sizeof(a.hostel_address));
    cout << a.hostel_address << endl;

    cout << "City: ";
    cin.getline(a.city, sizeof(a.city));
    cout << a.city << endl;

    cout << "State: ";
    cin.getline(a.state, sizeof(a.state));
    cout << a.state << endl;

    cout << "Zip: ";
    cin.getline(a.zip, sizeof(a.zip));
    cout << a.zip << endl;

    return 0;
}
