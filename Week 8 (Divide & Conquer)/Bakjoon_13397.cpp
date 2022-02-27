#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_SIZE 5001

using namespace std;

int MAP[MAX_SIZE];

int N, M;

void search(int left, int right) {
	int mid = (left + right) / 2;

	// end condition
	if (left == right) {
		cout << left << endl;
		exit(0);
	}

	int counter = 0;
	int index = 1;
	vector<int> temp;
	while (index <= N && counter < M) {
		temp.push_back(MAP[index]);
		if (temp.empty()) {
			index++;
		}
		else {
			// possible
			if (*max_element(temp.begin(), temp.end()) - *min_element(temp.begin(), temp.end()) <= mid) {
				index++;
			}
			else {
				counter++;
				temp.clear();
			}
		}
	}

	// success
	if (counter < M) {
		search(left, mid);
	}
	// fail
	else {
		search(mid + 1, right);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	int input_num;
	int max_num = -1;
	int min_num = 10001;
	int sum = 0;

	// input
	for (int index = 1; index <= N; index++) {
		cin >> input_num;
		MAP[index] = input_num;
		if (input_num > max_num) {
			max_num = input_num;
		}
		if (input_num < min_num) {
			min_num = input_num;
		}
		sum += input_num;
	}

	search(0, max_num - min_num);
	
}