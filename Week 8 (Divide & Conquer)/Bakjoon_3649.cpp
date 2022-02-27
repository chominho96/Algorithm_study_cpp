#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int x, n, l;

	while (true) {

		cin >> x >> n;
		x *= 10000000;

		if (cin.eof()) {
			break;
		}


		// exception : n == 0 || n == 1
		if (n == 0 || n == 1) {
			if (n == 1) {
				cin >> n;
			}
			cout << "danger\n";
			continue;
		}


		vector<int> vec;
		vec.reserve(n);
		
		for (int count = 0; count < n; count++) {
			cin >> l;
			vec.push_back(l);
		}

		sort(vec.begin(), vec.end());

		int left = 0;
		int right = n - 1;
		bool success = false;

		// find
		while (left < right) {

			if (vec[left] + vec[right] == x) {
				success = true;
				cout << "yes " << vec[left] << " " << vec[right] << "\n";
				break;
			}
			if (vec[left] + vec[right] > x) {
				right--;
			}
			else {
				left++;
			}


		}
		if (!success) {
			cout << "danger\n";
		}

		

	}
}