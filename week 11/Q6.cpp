#include <iostream>
#include <string>
using namespace std;

class BankAccount {
    string name;
    long accountNumber;
    string accountType;
    double balance;

public:
    void assign(string n, long accNo, string type, double initial) {
        name = n;
        accountNumber = accNo;
        accountType = type;
        balance = initial;
    }

    void deposit(double amount) {
        if (amount <= 0) {
            cout << "Invalid amount" << endl;
            return;
        }
        balance += amount;
        cout << "Deposited " << amount << ". New balance: " << balance << endl;
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "Invalid amount" << endl;
        } else if (amount > balance) {
            cout << "Insufficient balance. Current balance: " << balance << endl;
        } else {
            balance -= amount;
            cout << "Withdrawn " << amount << ". New balance: " << balance << endl;
        }
    }

    void display() {
        cout << "Depositor name : " << name << endl;
        cout << "Account number : " << accountNumber << endl;
        cout << "Account type   : " << accountType << endl;
        cout << "Balance        : " << balance << endl;
    }
};

int main() {
    BankAccount acc;
    string name, type;
    long accNo;
    double initial, amount;
    int choice;

    cout << "Depositor name: ";
    getline(cin, name);
    cout << "Account number: ";
    cin >> accNo;
    cout << "Account type: ";
    cin >> type;
    cout << "Initial balance: ";
    cin >> initial;

    acc.assign(name, accNo, type, initial);

    do {
        cout << endl;
        cout << "1. Deposit" << endl;
        cout << "2. Withdraw" << endl;
        cout << "3. Display account" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Amount to deposit: ";
            cin >> amount;
            acc.deposit(amount);
            break;
        case 2:
            cout << "Amount to withdraw: ";
            cin >> amount;
            acc.withdraw(amount);
            break;
        case 3:
            acc.display();
            break;
        case 4:
            break;
        default:
            cout << "Invalid choice" << endl;
        }
    } while (choice != 4);

    return 0;
}
