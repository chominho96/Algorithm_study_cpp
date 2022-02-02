#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct value_and_sequence {
	int value;
	int sequence;
};

struct compare {
	bool operator()(value_and_sequence& v_1, value_and_sequence& v_2) {
		return v_1.value < v_2.value;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, N, M, input_num;

	cin >> T;

	for (int count = 0; count < T; count++) {
		priority_queue<int> note_1;
		priority_queue<value_and_sequence, vector<value_and_sequence>, compare> note_2;
		vector<int> result;
		
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> input_num;		
			note_1.push(input_num);
		}

		cin >> M;
		result.resize(M);
		for (int index = 0; index < M; index++) {
			cin >> input_num;
			note_2.push(value_and_sequence{ input_num, index });
		}

		// compare
		while (!note_1.empty() && !note_2.empty()) {
			int n_1 = note_1.top();
			note_1.pop();
			value_and_sequence n_2 = note_2.top();
			note_2.pop();

			if (n_1 == n_2.value) {
				result[n_2.sequence] = 1;
				note_1.push(n_1);
			}
			else if (n_1 > n_2.value) {
				note_2.push(n_2);
			}
			else {
				result[n_2.sequence] = 0;
				note_1.push(n_1);
			}
		}

		while (!note_2.empty()) {
			value_and_sequence current = note_2.top();
			note_2.pop();
			result[current.sequence] = 0;
		}

		for (int index = 0; index < M; index++) {
			cout << result[index] << "\n";
		}


	}
}