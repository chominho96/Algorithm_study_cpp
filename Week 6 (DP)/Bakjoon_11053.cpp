#include <iostream>
#define MAX_SIZE 1001

using namespace std;

struct value_length {
	int value;
	int length = 0;
};

value_length DP[MAX_SIZE];

int main() {
	int T, A;
	cin >> T;

	for (int index = 1; index <= T; index++) {
		cin >> A;
		DP[index].value = A;
		DP[index].length = 1;
	}

	int result = 1;

	for (int i = 1; i <= T; i++) {
		for (int j = 1; j < i; j++) {
			if (DP[j].value < DP[i].value && DP[j].length + 1 > DP[i].length) {
				DP[i].length = DP[j].length + 1;
			}
		}

		if (DP[i].length > result) {
			result = DP[i].length;
		}
	}

	cout << result << endl;
}