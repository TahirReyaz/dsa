#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
		int m = board.size(), n = board[0].size();
		vector<vector<int>> nextState(m);

		for(int i = 0; i< m; i++) {
			for(int j = 0; j < n; j++) {
				int sum = 0;
				for(int k = -1; k < 2; k++) {
					for(int l = -1; l < 2; l++) {
						if(i-k>=0 && j-l>=0 && i-k<m && j-l<n) {
							sum += board[i-k][j-l];
						}
					}
				}
				sum-= board[i][j];
				if(board[i][j] == 0 && sum == 3) {
					nextState[i].push_back(1);
				} else if(board[i][j] == 1 && (sum == 2 || sum == 3)) {
					nextState[i].push_back(1);
				} else {
					nextState[i].push_back(0);
				}
			}
		}

        board = nextState;
    }
};

int main() {
	// Your code goes here;
	vector<vector<int>> board = {{0,1,0},{0,0,1},{1,1,1},{0,0,0}};
	Solution s;
	vector<vector<int>> ns = s.gameOfLife(board);
	int m = board.size(), n = board[0].size();

	cout<<"[";
	for(int i = 0; i< m; i++) {
		cout<<"[";
		for(int j = 0; j < n; j++) {
			cout<<ns[i][j]<<", ";
		}
		cout<<"]";
	}
	cout<<"]";
	return 0;
}