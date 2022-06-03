#include<iostream>
using namespace std;

void ArrayReversal(int *arr, int n) {
  int temp;
  for( int i = 0; i < (n / 2); i++) {
    swap(arr[i], arr[n-i-1]);
  }
}

int main()
{
  int arr[] = {23, 434, 345, 4, 234, 23, 15, 246, 64};
  int n = sizeof(arr) / sizeof(int);

  cout<<"Original Array: ";
  for(int i = 0; i < n; i++) {
    cout<<arr[i]<<" ";
  }

  ArrayReversal(arr, n);
  cout<<endl<<"Reversed Array: ";
  for(int i = 0; i < n; i++) {
    cout<<arr[i]<<" ";
  }
  
  return 0;
}