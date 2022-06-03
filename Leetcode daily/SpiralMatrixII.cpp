/*
Question-
Given a positive integer n, 
generate an n x n matrix filled with elements from 1 to n2 in spiral order.

Example-
Input: n = 3
Output: [[1,2,3],[8,9,4],[7,6,5]]
*/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
		int arr[n][n];
        int sr=0, sc=0, er=n-1, ec=n-1, count=1;
        vector<vector<int>> matrix(n);
        while(sr <= er && sc <= ec) {
			for(int i = sc; i <= ec; i++) {
				arr[sr][i] = count;
				count++;
			}
			sr++;
			for(int i = sr; i<= er; i++) {
				arr[i][ec] = count;
				count++;
			}
			ec--;
			for(int i = ec; i>=sc; i--) {
				arr[er][i] = count;
				count++;
			}
			er--;
			for(int i = er; i>=sr; i--) {
				arr[i][sc] = count;
				count++;
			}
			sc++;
		}
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                matrix[i].push_back(arr[i][j]);
            }
        }
		return matrix;
    }
};