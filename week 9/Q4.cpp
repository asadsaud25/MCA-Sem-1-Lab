#include <iostream>
using namespace std;

void swap_value(int a, int b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;

    cout << "After swapping (Call by Value):\n";
    cout << "First number = " << a << endl;
    cout << "Second number = " << b << endl;
}

void swap_reference(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;

    cout << "After swapping (Call by Reference):\n";
    cout << "First number = " << a << endl;
    cout << "Second number = " << b << endl;
}

int main()
{
    int x, y, choice;

    cout << "Enter two numbers: ";
    cin >> x >> y;

    cout << "\n1. Swap using Call by Value";
    cout << "\n2. Swap using Call by Reference";

    cout << "\nEnter your choice: ";
    cin >> choice;

    switch (choice)
    {
        case 1:
            swap_value(x, y);
            cout << "\nOriginal values remain unchanged:\n";
            cout << "First number = " << x << endl;
            cout << "Second number = " << y << endl;
            break;

        case 2:
            swap_reference(x, y);
            cout << "\nOriginal values are changed:\n";
            cout << "First number = " << x << endl;
            cout << "Second number = " << y << endl;
            break;

        default:
            cout << "Invalid choice!";
    }

    return 0;
}

