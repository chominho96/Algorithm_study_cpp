#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define MAX_SIZE 100001
#define INF 9999999

using namespace std;

struct idx_value {
	int idx;
	int value;
};

bool compare(const idx_value& i_1, const idx_value& i_2) {
	return i_1.value < i_2.value;
}

int MAP[MAX_SIZE];
vector<idx_value> block;

int N, M;

int result = INF;

void binary_search() {
	// find max
	idx_value current = *max_element(block.begin(), block.end(), compare);
	result = current.value;

	idx_value next;


	// EXCEPTION : rightmost / leftmost
	if (current.idx == M) {
		next = block[M - 1];
	}
	if (current.idx == 1) {
		next = block[M + 1];
	}

	// general case
	else {
		next = (block[M - 1].value < block[M + 1].value ? block[M - 1] : block[M + 1]);
	}
	
	int mid = (current.idx + next.idx) / 2;

	// end condition
	if (mid == current.idx || mid == next.idx) {
		cout << result << endl;
		exit(0);
	}

	int temp = current.value;

	if (mid > next.idx) {
		for (int i = next.idx + 1; i <= mid; i++) {
			next.value += MAP[i];
			temp -= MAP[i];
		}
	}
	else {
		for (int i = mid + 1; i <= current.idx; i++) {
			next.value += MAP[i];
			temp -= MAP[i];
		}
	}

	if (next.value < result) {


	}
	else if (temp < result) {

	}
	else {
		cout << result << endl;
		exit(0);
	}

	
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int course_length;
	int sum_of_length = 0;

	cin >> N >> M;

	block.resize(M + 1);

	// input
	for (int idx = 1; idx <= N; idx++) {
		cin >> course_length;
		MAP[idx] = course_length;
		sum_of_length += course_length;
	}

	// initialize block
	block[0] = idx_value{ 0, 0 };
	for (int idx = 1; idx < M; idx++) {
		block[idx] = idx_value{ idx, MAP[idx] };
		course_length -= MAP[idx];
	}
	block[M] = idx_value{ N, course_length };

	// binary search
	binary_search();
	
}