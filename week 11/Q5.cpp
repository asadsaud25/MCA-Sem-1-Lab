#include <iostream>
using namespace std;

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    return a / b;
}

int main() {
    double a, b;
    char op;

    cout << "Enter two numbers: ";
    cin >> a >> b;
    cout << "Enter the operation (+, -, *, /): ";
    cin >> op;

    switch (op) {
    case '+':
        cout << "Result: " << add(a, b) << endl;
        break;
    case '-':
        cout << "Result: " << subtract(a, b) << endl;
        break;
    case '*':
        cout << "Result: " << multiply(a, b) << endl;
        break;
    case '/':
        if (b == 0)
            cout << "Division by zero is not possible" << endl;
        else
            cout << "Result: " << divide(a, b) << endl;
        break;
    default:
        cout << "Invalid operation" << endl;
    }

    return 0;
}
