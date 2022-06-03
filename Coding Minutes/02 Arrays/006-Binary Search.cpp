#include<iostream>
using namespace std;

int BinarySearch (int * arr, int n, int e) {
  int l = 0, m, u = n - 1;
  m= (l + u) /2;
  while( l <= u) {
    if(arr[m] == e) {
      return m;
    } else if (arr[m] > e) {
      u = m - 1;
      m = ( l + u ) / 2;
    } else if ( arr[m] < e) {
      l = m + 1;
      m = ( l + u ) / 2;
    }
  }
  return -1;
}

int main()
{
  int arr[] = { 23, 34, 65, 76, 78, 98, 299, 349};
  int n = sizeof(arr)/ sizeof(int);
  int index = BinarySearch(arr, n, 98);

  if( index == -1 ) {
    cout<<"Element was not found";
  } else {
    cout<<"Element was found at "<<index;
  }
  return 0;
}