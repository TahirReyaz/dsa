#include <iostream>

using namespace std;

int fib(int n) {
	if(n==0 or n==1) {
		return n;
	}
	return fib(n-1) + fib(n-2);
}

int main() {
	// Your code goes here;
	int num = 8;
	cout<<fib(num);
	return 0;
}