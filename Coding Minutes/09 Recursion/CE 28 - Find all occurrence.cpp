#include <iostream>
#include <vector>

using namespace std;

vector<int> findAllOccurences(int k, vector<int> v){
    vector<int> output;
	int n = v.size(), last = v[n-1];
    if(n == 0) {
		return output;
	}
	v.pop_back();
	output = findAllOccurences(k, v);
	if(last == k) {
		output.push_back(v.size());
		return output;
	}
	return output;
}

int main() {
	vector<int> input = {1, 3, 7, 5, 7, 6, 2};
	vector<int> output = findAllOccurences(7, input);
	if(output.size() == 0) {
		cout<<"Not found";
	} else {
		for(int i = 0; i< output.size(); i++) {
			cout<<"Found at "<<output[i]<<endl;
		}
	}
	return 0;
}