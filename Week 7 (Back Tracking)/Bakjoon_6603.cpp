#include <iostream>
#include <vector>
#include <string>

using namespace std;

void combination(string prev_str, int target, int max, vector<string>& result) {
	string next = prev_str;
	next += ('a' + target - 1);
	// 1 is a and 2 is b ...

	// exit condition : it's size is max size
	if (next.size() == 6) {
		result.push_back(next);
		return;
	}
	
	for (int i = target + 1; i <= max; i++) {
		combination(next, i, max, result);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int k, S;

	while (true) {
		cin >> k;
		if (k == 0) {
			break;
		}

		vector<int> vec(k + 1);
		vector<string> result;

		// store original number
		for (int index = 1; index <= k; index++) {
			cin >> S;
			vec[index] = S;
		}

		// calculate relative position
		for (int index = 1; index <= k - 5; index++) {
			combination("", index, k, result);
		}

		// print
		for (int i = 0; i < result.size(); i++) {
			for (int j = 0; j < result[i].size(); j++) {
				cout << vec[result[i][j] - 96] << " ";
			}
			cout << "\n";
		}
		cout << "\n";
		
	}
}