#include <iostream>

using namespace std; 
int main() {
	int sum = 0;
	
	int arr[] = {1, 2, 3, 4, 5};
	int size = sizeof(arr)/sizeof(arr[0]);
	for(int i=0; i<size; i++) {
		sum += arr[i];
	}
	cout << "Sum of all elements = " << sum;
	return 0;
}
