#include <iostream>
using namespace std;

struct Complex {
    double real;
    double imag;
};

Complex readComplex() {
    Complex c;
    cout << "Enter real part: ";
    cin >> c.real;
    cout << "Enter imaginary part: ";
    cin >> c.imag;
    return c;
}

void writeComplex(const Complex &c) {
    cout << c.real;
    if (c.imag >= 0)
        cout << " + " << c.imag << "i";
    else
        cout << " - " << -c.imag << "i";
    cout << endl;
}

Complex addComplex(const Complex &a, const Complex &b) {
    Complex r;
    r.real = a.real + b.real;
    r.imag = a.imag + b.imag;
    return r;
}

Complex subComplex(const Complex &a, const Complex &b) {
    Complex r;
    r.real = a.real - b.real;
    r.imag = a.imag - b.imag;
    return r;
}

Complex mulComplex(const Complex &a, const Complex &b) {
    Complex r;
    r.real = a.real * b.real - a.imag * b.imag;
    r.imag = a.real * b.imag + a.imag * b.real;
    return r;
}

int main() {
    cout << "First complex number" << endl;
    Complex a = readComplex();
    cout << "Second complex number" << endl;
    Complex b = readComplex();

    cout << "First number: ";
    writeComplex(a);
    cout << "Second number: ";
    writeComplex(b);

    cout << "Sum: ";
    writeComplex(addComplex(a, b));
    cout << "Difference: ";
    writeComplex(subComplex(a, b));
    cout << "Product: ";
    writeComplex(mulComplex(a, b));
    return 0;
}
