#include <iostream>
#define MAX_SIZE 101

using namespace std;

long long DP[MAX_SIZE]{0, 1, 1, 1, 2, 2};
// not use index 0

int main() {
	
	// initialize array
	for (int index = 6; index < MAX_SIZE; index++) {
		DP[index] = DP[index - 5] + DP[index - 1];
		// Recurrence relation
		// A[i] = A[i - 5] + A[i - 1]
	}

	int T, N;

	cin >> T;

	for (int count = 0; count < T; count++) {
		cin >> N;
		cout << DP[N] << "\n";
	}
	
}