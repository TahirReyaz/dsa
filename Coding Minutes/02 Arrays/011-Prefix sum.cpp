#include<iostream>
using namespace std;

void Subarrays(int *arr, int n) {
  int largest = 0, int prefSum[n];
  prefSum[0] = arr[0];
  cout<<"The sums of the subarrays are: ";
  for(int i = 1; i < n; i++) {
    prefSum[i] = prefSum[i-1] + arr[i];
  }
  cout<<endl<<"The largest of these sums is: "<<largest;
}
int main()
{
  int arr[] = {1, -2, 3, 4, 5};
  int n = sizeof(arr) / sizeof(int);

  Subarrays(arr, n);
  return 0;
}