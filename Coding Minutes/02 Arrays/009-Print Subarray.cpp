#include<iostream>
using namespace std;

void Subarrays(int *arr, int n) {
  for(int i = 0; i < n; i++) {
    for(int j = i + 1 ; j <= n; j++) {
      cout<<"[";
      for( int k = i; k < j; k++) {
        cout<<arr[k]<<" ";
      }
      cout<<"] ";
    }
    cout<<endl;
  }
}
int main()
{
  int arr[] = {1, 2, 3, 4, 5};
  int n = sizeof(arr) / sizeof(int);

  Subarrays(arr, n);
  return 0;
}