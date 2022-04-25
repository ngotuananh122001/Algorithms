#include <iostream>
#include <vector>
using namespace std;

vector<int> rotateArray(vector<int> &A, int B) {
	vector<int> ret;

	for (int i = 0; i < A.size(); i++) {
		ret.push_back(A[(i+B) % A.size()]);
	}

	return ret;
}

int main() {
	vector<int> nums = {1, 2, 3};

	vector<int> ret = rotateArray(nums, 4);

	for (auto num : ret)
		cout << num << " ";
	return 0;
}