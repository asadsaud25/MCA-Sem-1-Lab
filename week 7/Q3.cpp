#include<iostream>
#include<cmath>
using namespace std;

int main(){
	int n;
	cout << "enter size: ";
	cin >> n;
	float arr[n];
	float sum = 0;
	float mean = 0;
	float sd = 0;
	
	cout<<"enter elements: "<<endl;
	for(int i = 0;i<n;i++){
		cin >> arr[i];
		sum = sum +arr[i];
	}
	mean = sum/n;
	float ssum = 0;
	for(int i = 0; i<n; i++){
		ssum = ssum + (arr[i]-mean)*(arr[i]-mean);
	}
	sd = sqrt((1.0/n)*ssum);
	cout << sum << endl << mean << endl << sd;
	
}
