#include <iostream>
#include <vector>

using namespace std;

vector<int> increasingNumbers(int N) {
	vector<int> output;
    if(N == 0) {
		return output;
	}
	output = increasingNumbers(N-1);
	output.push_back(N);
	return output;
}

int main() {
	int n = 5;
	vector<int> output = increasingNumbers(n);
	for(int i = 0; i< output.size(); i++) {
		cout<<output[i]<<" ";
	}
	return 0;
}