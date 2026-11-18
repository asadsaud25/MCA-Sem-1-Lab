#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int N = 100;

struct Employee {
    string name;
    double basic;
    double da;
    double gross;
};

int main() {
    Employee emp[N];

    for (int i = 0; i < N; i++) {
        cout << "Employee " << i + 1 << " name: ";
        getline(cin >> ws, emp[i].name);
        cout << "Employee " << i + 1 << " basic pay: ";
        cin >> emp[i].basic;
        emp[i].da = 0.52 * emp[i].basic;
        emp[i].gross = emp[i].basic + emp[i].da;
    }

    cout << endl << left << setw(25) << "Name" << "Gross Salary" << endl;
    cout << fixed << setprecision(2);
    for (int i = 0; i < N; i++)
        cout << left << setw(25) << emp[i].name << emp[i].gross << endl;
    return 0;
}
