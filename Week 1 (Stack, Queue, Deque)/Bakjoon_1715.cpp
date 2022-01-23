#include <iostream>
#include <queue>

using namespace std;

int main() {
	int N, paper;
	cin >> N;

	priority_queue<int, vector<int>, greater<int>> que;
	for (int count = 0; count < N; count++) {
		cin >> paper;
		que.push(paper);
	}

	// exception : N == 1
	if (N == 1) {
		cout << 0;
		return 0;
	}
	
	int result = 0;
	while (que.size() != 1) {
		int data_1 = que.top();
		que.pop();
		int data_2 = que.top();
		que.pop();

		result += (data_1 + data_2);


		que.push(data_1 + data_2);

	}

	cout << result << endl;

	
}