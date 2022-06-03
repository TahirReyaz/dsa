#include<iostream>
using namespace std;

void Subarrays(int *arr, int n) {
  int largest = 0;
  cout<<"The sums of the subarrays are: ";
  for(int i = 0; i < n; i++) {
    for(int j = i + 1 ; j <= n; j++) {
      int sum = 0;
      for( int k = i; k < j; k++) {
        sum += arr[k];
      }
      cout<<sum<<", ";
      largest = max(largest, sum);
    }
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