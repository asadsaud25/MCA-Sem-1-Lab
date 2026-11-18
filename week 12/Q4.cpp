#include <iostream>
using namespace std;

class Counter {
    static int created;
    static int destroyed;
    int id;

public:
    Counter() {
        created++;
        id = created;
        cout << "Object " << id << " created" << endl;
    }

    ~Counter() {
        destroyed++;
        cout << "Object " << id << " destroyed" << endl;
    }

    static void show() {
        cout << "Created: " << created << ", Destroyed: " << destroyed
             << ", Alive: " << created - destroyed << endl;
    }
};

int Counter::created = 0;
int Counter::destroyed = 0;

int main() {
    cout << "Entering main block" << endl;
    Counter a;
    Counter::show();

    {
        cout << "Entering block 1" << endl;
        Counter b, c;
        Counter::show();
        cout << "Leaving block 1" << endl;
    }
    Counter::show();

    {
        cout << "Entering block 2" << endl;
        Counter d;
        {
            cout << "Entering nested block" << endl;
            Counter e;
            Counter::show();
            cout << "Leaving nested block" << endl;
        }
        Counter::show();
        cout << "Leaving block 2" << endl;
    }
    Counter::show();

    cout << "Leaving main block" << endl;
    return 0;
}
