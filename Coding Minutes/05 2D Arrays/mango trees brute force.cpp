#include <iostream>

using namespace std;

pair<int, int> cutPos(char arr[][6], int n, int m) {
	pair <int, int> pos;
	int largest_sum=0, max_result = 0, num_of_trees, min_num;
	for(int i=1; i < n; i++) {
		for(int j = 1; j < m; j++) {
			min_num = n*m;

			//2nd quad
			num_of_trees = 0;
			for(int k = 0; k < i; k++) {
				for( int l = 0; l < j; l++) {
					if(arr[k][l] == '#') {
						num_of_trees++;
					}
				}
			}
			min_num = min(min_num, num_of_trees);
			
			//1st quad
			num_of_trees = 0;
			for(int k = 0; k < i; k++) {
				for( int l = j; l < m; l++) {
					if(arr[k][l] == '#') {
						num_of_trees++;
					}
				}
			}
			min_num = min(min_num, num_of_trees);

			// 4th quad
			num_of_trees = 0;
			for(int k = i; k < n; k++) {
				for( int l = j; l < m; l++) {
					if(arr[k][l] == '#') {
						num_of_trees++;
					}
				}
			}
			min_num = min(min_num, num_of_trees);

			// 3rd quad
			num_of_trees = 0;
			for(int k = i; k < n; k++) {
				for( int l = 0; l < j; l++) {
					if(arr[k][l] == '#') {
						num_of_trees++;
					}
				}
			}
			min_num = min(min_num, num_of_trees);

			// Compare and update
			if(min_num > max_result) {
				pos={i, j};
				max_result = min_num;
			}
		}
	}

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