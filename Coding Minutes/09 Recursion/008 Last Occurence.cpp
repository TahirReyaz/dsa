#include <iostream>

using namespace std;

int lastOcc(int arr[], int n, int e) {
	if(n==0) {
		return -1;
	}
	if(arr[n-1] == e) {
		return n-1;
	}
	return lastOcc(arr, n - 1, e);
}

int main() {
	int arr[] = {1, 3, 5, 7, 6, 2};
	int n = sizeof(arr)/ sizeof(int);
	cout<<"It was found at: "<<lastOcc(arr, n, 4)<<endl;
	return 0;
}