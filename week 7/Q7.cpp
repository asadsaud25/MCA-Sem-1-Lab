#include <iostream>
using namespace std;

class Student{
	int r;
	public:
		void set(int n) {
			this->r = n;
		}
		Student& refer() {
			return *this;
		}
		void display() {
			cout << "Roll no: " << r << endl;
		}
};
int main() {
	Student s1;
	s1.set(41);
	Student& r = s1.refer();
	r.display();
	return 0;
}
