#include <iostream>
#define MAX_SIZE 41

using namespace std;

struct zero_one {
	int zero;
	int one;
};

zero_one DP[MAX_SIZE];

int main() {

	DP[0].zero = 1;
	DP[0].one = 0;
	DP[1].zero = 0;
	DP[1].one = 1;

	for (int index = 2; index < MAX_SIZE; index++) {
		DP[index].zero = DP[index - 2].zero + DP[index - 1].zero;
		DP[index].one = DP[index - 2].one + DP[index - 1].one;
	}

	int T, N;

	cin >> T;

	for (int count = 0; count < T; count++) {
		cin >> N;

		cout << DP[N].zero << " " << DP[N].one << endl;
	}

}