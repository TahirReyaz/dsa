#include <iostream>

using namespace std;

int factorial(int n) {
	if(n == 1) {
		return 1;
	}
	return n * factorial(n-1);
}

int main() {
	// Your code goes here;
	int num = 5;
	cout<<factorial(5);
	return 0;
}