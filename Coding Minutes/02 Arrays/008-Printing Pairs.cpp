#include<iostream>
using namespace std;

void PrintPairs(int *arr, int n) {
  for(int i = 0; i < n -1; i++) {
    for(int j = i + 1; j < n; j++) {
      cout<<"("<<arr[i]<<", "<<arr[j]<<"), ";
    }
    cout<<endl;
  }
}
int main()
{
  int arr[] = {1, 2, 3, 4, 5};
  int n = sizeof(arr) / sizeof(int);

  PrintPairs(arr, n);
  return 0;
}