#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define INF 2000000000

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, input_num;
	cin >> N;

	vector<int> vec(N);


	for (int index = 0; index < N; index++) {
		cin >> input_num;
		vec[index] = input_num;
	}

	sort(vec.begin(), vec.end());

	if (vec[N - 1] >= 0 && vec[0] >= 0) {
		cout << vec[0] << " " << vec[1] << endl;
	}
	else if (vec[N - 1] <= 0 && vec[0] <= 0) {
		cout << vec[N - 2] << " " << vec[N - 1] << endl;
	}
	else {
		int start = 0;
		int end = N - 1;

		int result = INF;
		int result_start = vec[start];
		int result_end = vec[end];

		while (start < end) {
			if (abs(vec[start] + vec[end]) < result) {
				result = abs(vec[start] + vec[end]);
				result_start = vec[start];
				result_end = vec[end];
			}
			if (vec[start] + vec[end] == 0) {
				break;
			}
			else if (vec[start] + vec[end] > 0) {
				end--;
			}
			else {
				start++;
			}
		}
		
		cout << result_start << " " << result_end << endl;
	}
	
}