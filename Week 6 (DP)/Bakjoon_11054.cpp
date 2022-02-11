#include <iostream>
#include <queue>
#define MAX_SIZE 1001

using namespace std;

struct value_length {
	int value;
	int increase_length;
	int decrease_length;
};

value_length DP[MAX_SIZE];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, A;
	cin >> N;

	for (int index = 1; index <= N; index++) {
		cin >> A;
		DP[index].value = A;
	}

	if (N == 1) {
		cout << 1 << endl;
		return 0;
	}

	DP[1].increase_length = 1;
	DP[N].decrease_length = 1;

	// 1. calculate increase length

	for (int index = 2; index <= N; index++) {
		int result_length = 0;
		int current = DP[index].value;

		for (int i = index - 1; i >= 1; i--) {
			if (DP[i].value < current && DP[i].increase_length > result_length) {
				result_length = DP[i].increase_length;
			}
		}
		DP[index].increase_length = result_length + 1;
	}


	priority_queue<int> result;

	// 2. calculate decrease length and calculate result
	for (int index = N - 1; index >= 1; index--) {
		int result_length = 0;
		int current = DP[index].value;

		for (int i = index + 1; i <= N; i++) {
			if (DP[i].value < current && DP[i].decrease_length > result_length) {
				result_length = DP[i].decrease_length;
			}
		}
		DP[index].decrease_length = result_length + 1;

		result.push(DP[index].decrease_length + DP[index].increase_length);
	}
	result.push(DP[N].increase_length + DP[N].decrease_length);


	cout << result.top() - 1 << endl;
	
	
}