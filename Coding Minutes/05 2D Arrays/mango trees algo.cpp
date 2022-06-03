// Question:
// There is field in form of a matrix, each cell is either empty or filled with
// a mango tree. Divide the field in 4 parts by cutting at point.
// The main character takes the field with smallest number of trees.
// Find where to make the cut that the main character gets maximum trees he can.

// Solution:
// Create a matrix in which each element stores how many trees are there in the
// rectangle made by it and (0, 0)
// Make a cut at every point and calculate the num of trees in each quadrant
// by using the prefix sum matrix and hence get the result 

#include <iostream>

using namespace std;

pair<int, int> cutPos(char arr[][6], int n, int m) {
	pair <int, int> pos;
	int largest_sum=0, max_result = 0, min_num;
	int matrix[n][m];

	// Compute the 2D prefix sum matrix
	for(int i=0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			int um = 0, lm= 0, ulm = 0;
			if(i == 0 && j == 0) {
				um = 0; lm = 0; ulm = 0;
			} else if(i == 0) {
				um = 0; ulm = 0;
				lm = matrix[i][j-1];
			} else if(j == 0) {
				lm = 0; ulm = 0;
				um = matrix[i - 1][j];
			} else {
				lm = matrix[i][j-1];
				um = matrix[i - 1][j];
				ulm = matrix[i-1][j-1];
			}
			matrix[i][j] = um + lm - ulm;
			if(arr[i][j] == '#') {
				matrix[i][j]++;
			}
		}
	}

	// Compute the position of the cut
	for(int i=1; i < n; i++) {
		for(int j = 1; j < m; j++) {
			min_num = matrix[n-1][m-1];

			//2nd quad
			int quad2 = matrix[i-1][j-1];
			min_num = min(min_num, quad2);
			
			//1st quad
			int quad1 = matrix[i-1][m-1] - quad2;
			min_num = min(min_num, quad1);

			// 3rd quad
			int quad3 = matrix[n-1][j-1] - quad2;
			min_num = min(min_num, quad3);

			// 4th quad
			int quad4 = matrix[n-1][m-1] - quad1 - quad2 - quad3;
			min_num = min(min_num, quad4);

			// Compare and update
			if(min_num > max_result) {
				pos={i, j};
				max_result = min_num;
			}
		}
	}

	for(int i=0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cout<<matrix[i][j]<<", ";
		}
		cout<<endl;
	}
	cout<<endl;
	return pos;
}

int main() {
	// Your code goes here;
	char arr[][6] = {
					{'.', '#', '#', '.', '.', '.' },
					{'#', '.', '.', '#', '#', '.' },
					{'.', '#', '.', '.', '.', '.' },
					{'.', '#', '#', '.', '.', '#' },
					{'#', '.', '.', '#', '#', '.' },
					{'.', '#', '.', '.', '.', '.' }
					};
	int n = 6, m = 6;
	pair<int, int> pos;

	pos = cutPos(arr, n, m);

	// cout<<"Cut at ["<<pos.first<<", "<<pos.second<<"]"<<endl;

	// Print the output array
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(j == pos.second) {
				cout<<"| ";
			}
			cout<<arr[i][j]<<" ";
		}
		
		if(i == pos.first - 1) {
			cout<<endl;
			for(int j = 0; j < m; j++) {
				cout<<"- ";
			}
			cout<<"- ";
		}
		cout<<endl;
	}

	return 0;
}