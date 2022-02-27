#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int block[20]{ 0 };
int square[20];
int sum = 0;


void find(int length, int width, int height) {
	
	// end condition
	if (length <= 0 || width <= 0 || height <= 0) {
		return;
	}

	bool success = false;
	int result;
	for (int i = 19; i >= 0; i--) {
		if (length >= square[i] && width >= square[i] && height >= square[i] && block[i] > 0) {
			// if can use
			block[i]--;
			sum++;
			result = square[i];
			success = true;
			break;
		}
	}

	if (!success) {
		cout << "-1\n";
		exit(0);
	}

	// go next
	find(length, width, height - result);
	find(length, width - result, result);
	find(length - result, result, result);

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// initialize
	for (int count = 0; count <= 19; count++) {
		square[count] = int(pow(2, count));
	}

	int l, w, h, N, A, B;
	cin >> l >> w >> h;

	// input
	cin >> N;
	for (int count = 0; count < N; count++) {
		cin >> A >> B;
		block[A] = B;
	}

	find(l, w, h);


	cout << sum << endl;

}