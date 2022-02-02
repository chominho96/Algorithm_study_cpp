#include <iostream>
#include <vector>
#define MAX_SIZE 1000001


int MAP[MAX_SIZE];
// value is sequence
// example : MAP[5] == 3 means a3's value is 5

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// initialize
	for (int i = 0; i < MAX_SIZE; i++) {
		MAP[i] = -1;
	}

	int n, x, input_num;

	cin >> n;
	vector<int> num_vec(n);

	for (int index = 0; index < n; index++) {
		cin >> input_num;
		num_vec[index] = input_num;
		MAP[input_num] = index;
	}

	cin >> x;

	int result = 0;

	for (int index = 0; index < n; index++) {
		int current = num_vec[index];


		if (x - current < MAX_SIZE && x - current >= 0 && MAP[x - current] > index) {
			result++;
		}
	}

	cout << result << endl;
}