#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int tree[1025];
vector<int> result[11];
// not use index 0

int main() {
	int K;
	cin >> K;

	int seq;
	for (int index = 1; index <= int(pow(2, K)) - 1; index++) {
		cin >> seq;
		tree[index] = seq;
	}
	for (int count = 1; count <= K; count++) {
		int unit = int(pow(2, count));
		for (int index = int(pow(2, count - 1)); index < int(pow(2, K)); index += unit) {
			result[count].push_back(tree[index]);
		}
	}
	for (int count = K; count >= 1; count--) {
		for (int index = 0; index < result[count].size(); index++) {
			cout << result[count][index] << " ";
		}
		cout << endl;
	}
	
}