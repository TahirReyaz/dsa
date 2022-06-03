#include <iostream>

using namespace std;

int firstOcc(int arr[], int i, int n, int e) {
	if(n == i) {
		return -1;
	}
	if(arr[i] == e) {
		return i;
	}
	return firstOcc(arr, i+1, n, e);
}

int firstOcc2(int arr[], int n, int e) {
	if(n==0) {
		return -1;
	}
	if(arr[0] == e) {
		return 0;
	}
	int pos = firstOcc2(arr + 1, n - 1, e);
	if(pos < 0) {
		return -1;
	} else {
		return pos + 1;
	}
}

int main() {
	int arr[] = {1, 3, 5, 7, 6, 2};
	int n = sizeof(arr)/ sizeof(int);
	cout<<"From 1st function, it was found at: "<<firstOcc(arr, 0, n, 7)<<endl;
	cout<<"From 2nd function, it was found at: "<<firstOcc2(arr, n, 7)<<endl;
	return 0;
}