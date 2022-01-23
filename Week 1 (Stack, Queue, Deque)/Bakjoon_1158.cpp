#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	// input

	queue<int> que;
	vector<int> result;
	result.reserve(5000);
	// store result

	for (int count = 1; count <= N; count++) {
		// queue initialize
		que.push(count);
	}

	while (!que.empty()) {
		int pos = K % que.size();
		// if pos == 1, it indicates first data
		// if pos == 0, it indicates last data

		int count;
		if (pos == 0) {
			// exception case : last data
			count = que.size() - 1;
		}
		else {
			count = pos - 1;
		}
		
		for (int i = 0; i < count; i++) {
			// readjust position of data
			que.push(que.front());
			que.pop();
		}
		result.push_back(que.front());
		que.pop();
		
	}

	// print
	cout << "<";
	for (int index = 0; index < result.size() - 1; index++) {
		cout << result[index] << ", ";
	}
	cout << result[result.size() - 1] << ">" << endl;
}