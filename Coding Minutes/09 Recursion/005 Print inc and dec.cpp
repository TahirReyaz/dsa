#include <iostream>

using namespace std;

void printInc(int n) {
	if(n==0) {
		return;
	}
	printInc(n-1);
	cout<<n<<" ";
	return;
}

void printDec(int n) {
	if(n==0) {
		return;
	}
	cout<<n<<" ";
	printDec(n-1);
	return;
}

int main() {
	// Your code goes here;
	int n = 5;
	cout<<"Inc: ";
	printInc(n);
	cout<<endl<<"Dec: ";
	printDec(n);
	return 0;
}