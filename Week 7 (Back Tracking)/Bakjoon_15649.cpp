#include <iostream>
#include <string>
#include <vector>
#define MAX_SIZE 9
#define MAX_MEMORY 2000

using namespace std;


void combination(string prev_str, int target, int size, int max) {
	// break condition
	for (int index = 0; index < prev_str.size(); index++) {
		if (prev_str[index] - '0' == target) {
			return;
		}
	}

	// add target
	string curr_str = prev_str += to_string(target);

	if (curr_str.size() == size) {
		for (int i = 0; i < size; i++) {
			cout << curr_str[i] << " ";
		}
		cout << "\n";
		return;
	}

	// next
	for (int index = 1; index <= max; index++) {
		combination(curr_str, index, size, max);
	}
	
}

int main() {
	int N, M;

	cin >> N >> M;

	for (int index = 1; index <= N; index++) {
		combination("", index, M, N);
	}

}