#include <iostream>
using namespace std;

class greatest{
	int a;
	int b;
	
	public:
		void set(int a, int b) {
			this->a = a;
			this->b = b;
		}
		void print() {
			cout << "a = " << a << endl;
			cout << "b = " << b << endl;
			cout << endl;
		}
		void max() {
			if (this->a > this->b) {
				cout << "Greatest no. is " << a;
			}
			else {
				cout << "Greatest no. is " << b;
			}
		}
};

int main() {
	greatest a1;
	a1.set(21, 89);
	a1.print();
	a1.max();
}
