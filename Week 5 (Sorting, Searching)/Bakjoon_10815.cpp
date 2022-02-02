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

	int N, M, input_num;

	priority_queue<int> card_1;
	priority_queue<value_and_sequence, vector<value_and_sequence>, compare> card_2;
	vector<int> result;

	cin >> N;
	for (int count = 0; count < N; count++) {
		cin >> input_num;
		card_1.push(input_num);
	}

	cin >> M;
	result.resize(M);
	for (int index = 0; index < M; index++) {
		cin >> input_num;
		card_2.push(value_and_sequence{ input_num, index });
	}

	while (!card_1.empty() && !card_2.empty()) {
		int c_1 = card_1.top();
		value_and_sequence c_2 = card_2.top();

		card_1.pop();
		card_2.pop();

		if (c_1 == c_2.value) {
			card_1.push(c_1);
			result[c_2.sequence] = 1;
		}
		else if (c_1 > c_2.value) {
			card_2.push(c_2);
		}
		else {
			card_1.push(c_1);
			result[c_2.sequence] = 0;
		}
	}

	while (!card_2.empty()) {
		value_and_sequence current = card_2.top();
		card_2.pop();

		result[current.sequence] = 0;
	}

	for (int index = 0; index < M; index++) {
		cout << result[index] << " ";
	}
}