#include <iostream>
using namespace std;

class pntr_obj {
	int rollNo;
	string name;
	
	public:
		void set(int r, string n) {
			this->name = n;
			this->rollNo = r;
		}
		void print() {
			cout << "name: " << this->name << endl;
			cout << "roll no: " << this->rollNo << endl;
			cout << endl;
		}
};
int main() {
	pntr_obj o1, o2, o3;
	o1.set(101, "xyz");
	o2.set(102, "abc");
	o3.set(103,"pqr");
	
	o1.print();
	o2.print();
	o3.print();
}
