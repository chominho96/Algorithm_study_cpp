#include <iostream>
#define MAX_SIZE 21

using namespace std;

int MAP[MAX_SIZE];

int result = 0;

void combination(int target_num, int current_num, int current_index, int current_size, int max_size) {
	if (current_num == target_num) {
		result++;
	}

	for (int index = current_index + 1; index <= max_size; index++) {
		combination(target_num, current_num + MAP[index], index, current_size + 1, max_size);
	}
}

int main() {
	int N, S, input_num;

	cin >> N >> S;

	for (int index = 1; index <= N; index++) {
		cin >> input_num;
		MAP[index] = input_num;
	}

	for (int index = 1; index <= N; index++) {
		combination(S, MAP[index], index, 1, N);
	}

	cout << result << endl;
}