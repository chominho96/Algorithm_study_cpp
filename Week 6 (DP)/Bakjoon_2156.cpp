#include <iostream>
#include <cmath>
#define MAX_SIZE 10001

using namespace std;

struct wine {
	int value;
	int double_max;
	int no_double_max;
	int not_selected;
};

wine DP[MAX_SIZE];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, input_num;
	cin >> n;

	// input
	for (int index = 1; index <= n; index++) {
		cin >> input_num;
		DP[index].value = input_num;
	}

	// exception case
	if (n == 1) {
		cout << DP[1].value << endl;
		return 0;
	}
	
	// make array
	DP[1].double_max = 0;
	DP[1].no_double_max = DP[1].value;
	DP[1].not_selected = 0;

	DP[2].double_max = DP[1].value + DP[2].value;
	DP[2].no_double_max = DP[2].value;
	DP[2].not_selected = DP[1].value;

	int result = DP[2].double_max;

	for (int index = 3; index <= n; index++) {
		// 1. no_double_max
		DP[index].double_max = DP[index - 1].no_double_max + DP[index].value;

		if (DP[index].double_max > result) {
			result = DP[index].double_max;
		}

		// 2. double_max
		DP[index].no_double_max = max(DP[index - 2].double_max, max(DP[index - 2].no_double_max, DP[index - 1].not_selected)) + DP[index].value;

		if (DP[index].no_double_max > result) {
			result = DP[index].no_double_max;
		}

		// 3. not_selected
		DP[index].not_selected = max(DP[index - 1].double_max, max(DP[index - 1].no_double_max, DP[index - 1].not_selected));

	}

	

	cout << result << endl;
}