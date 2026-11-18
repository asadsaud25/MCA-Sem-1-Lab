#include <iostream>
#include <cmath>
using namespace std;

class Triangle {
    double base;
    double height;

public:
    Triangle(double b, double h) {
        base = b;
        height = h;
    }

    double hypo() {
        return sqrt(base * base + height * height);
    }

    double area() {
        return 0.5 * base * height;
    }
};

int main() {
    double b, h;
    cout << "Enter the base: ";
    cin >> b;
    cout << "Enter the height: ";
    cin >> h;

    Triangle t(b, h);
    cout << "Hypotenuse: " << t.hypo() << endl;
    cout << "Area: " << t.area() << endl;
    return 0;
}
