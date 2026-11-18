#include <iostream>
using namespace std;

class Sample {
    int a;
    int b;

public:
    Sample() {
        a = 10;
        b = 20;
    }

    void display() {
        cout << "a = " << a << endl;
        cout << "b = " << b << endl;
    }
};

int main() {
    Sample s;
    s.display();
    return 0;
}
