#include <iostream>
using namespace std;

class Calculator {
    double a, b, c, d;

public:
    Calculator() {
        a = b = c = d = 0;
    }

    Calculator(double x) {
        a = b = c = d = x;
    }

    Calculator(double x, double y) {
        a = x;
        b = y;
        c = 0;
        d = 0;
    }

    Calculator(double x, double y, double z, double w) {
        a = x;
        b = y;
        c = z;
        d = w;
    }

    void compute() {
        cout << "Values: " << a << ", " << b << ", " << c << ", " << d << endl;
        cout << "Sum: " << a + b + c + d << endl;
        cout << "Difference (a - b - c - d): " << a - b - c - d << endl;
        cout << "Product: " << a * b * c * d << endl;
        if (b == 0 || c == 0 || d == 0)
            cout << "Division (a / b / c / d): not possible, a divisor is zero" << endl;
        else
            cout << "Division (a / b / c / d): " << a / b / c / d << endl;
    }
};

int main() {
    Calculator c1;
    Calculator c2(5);
    Calculator c3(8, 2);
    Calculator c4(100, 2, 5, 2);

    cout << "Default constructor" << endl;
    c1.compute();
    cout << endl << "One argument" << endl;
    c2.compute();
    cout << endl << "Two arguments" << endl;
    c3.compute();
    cout << endl << "Four arguments" << endl;
    c4.compute();
    return 0;
}
