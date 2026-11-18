#include <iostream>
using namespace std;

class Flight{
	int fno;
	string source, destination;
	float fair;
	
	public:
		void set(int fno, string s,string d,float fair) {
			this->fno = fno;
			this->source = s;
			this->destination = d;
			this->fair = fair;
		}
		
		void print() {
			cout << "Flight No.: " << this->fno << endl;
			cout << "Source: " <<this->source << endl;
			cout << "Destination: " << this->destination << endl;
			cout << "fair: $" << this->fair << endl;
			cout << endl;
		}
};
int main() {
	Flight f1, f2, f3;
	f1.set(10101, "Delhi", "Lucknow", 300);
	f2.set(89122, "Purani Chungi", "Etah Chungi", 1);
	cout << "\t\tFlight Details\n\n" << endl;
	f1.print();
	f2.print();
	
	return 0;
}
