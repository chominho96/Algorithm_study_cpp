#include <iostream>
#define MAX_SIZE 301

using namespace std;

struct value_and_stack {
	int value;
	// store min value to come here
	int max_no_double;
	int max_double;

};

value_and_stack DP[MAX_SIZE];

int main() {
	int T, N;
	cin >> T;

	for (int index = 1; index <= T; index++) {
		cin >> N;
		DP[index].value = N;
	}

	DP[1].max_no_double = DP[1].value;
	DP[1].max_double = DP[1].value;
	DP[2].max_no_double = DP[2].value;

	
	// make array
	for (int index = 1; index <= T - 2; index++) {
		// set +2
		if (DP[index].max_no_double > DP[index].max_double) {
			DP[index + 2].max_no_double = DP[index].max_no_double + DP[index + 2].value;
		}
		else {
			DP[index + 2].max_no_double = DP[index].max_double + DP[index + 2].value;
		}

		// set +1
		DP[index + 1].max_double = DP[index].max_no_double + DP[index + 1].value;
	}

	// print
	int double_prev_result = (DP[T - 2].max_no_double > DP[T - 2].max_double ? DP[T - 2].max_no_double : DP[T - 2].max_double);
	if (DP[T - 1].max_no_double > double_prev_result) {
		cout << DP[T - 1].max_no_double + DP[T].value << endl;
	}
	else {
		cout << double_prev_result + DP[T].value << endl;
	}

}