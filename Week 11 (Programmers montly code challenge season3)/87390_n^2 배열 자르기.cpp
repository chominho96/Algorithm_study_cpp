#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
	vector<int> answer;

	long long long_n = n;

	long long left_level, right_level, left_discard, right_discard;
	if (left == 0) {
		left_level = 1;
		left_discard = 0;
	}
	else {
		left_level = left / long_n + 1;
		left_discard = left % long_n;
	}
	
	if (right == 0) {
		right_level = 1;
		right_discard = long_n - 1;
	}
	else {
		right_level = right / long_n + 1;
		right_discard = long_n - (right % long_n) - 1;
	}


	answer.reserve(right - left + 1);

	// EXCEPTION : left_level == right_level
	if (left_level == right_level) {
		long long cnt = 0;
		for (long long i = 0; i < left_level; i++) {
			if (cnt < left_discard) {
				cnt++;
			}
			else if (cnt >= long_n - right_discard) {
				break;
			}
			else {
				answer.push_back(left_level);
				cnt++;
			}
		}
		for (long long i = left_level + 1; i <= long_n; i++) {
			if (cnt < left_discard) {
				cnt++;
			}
			else if(cnt >= long_n - right_discard) {
				break;
			}
			else {
				answer.push_back(i);
				cnt++;
			}
		}

		return answer;
	}

	// first
	long long cnt = 0;
	for (long long i = 0; i < left_level; i++) {
		if (cnt < left_discard) {
			cnt++;
		}
		else {
			answer.push_back(left_level);
		}
	}
	for (long long i = left_level + 1; i <= long_n; i++) {
		if (cnt < left_discard) {
			cnt++;
		}
		else {
			answer.push_back(i);
		}
	}

	
	

	// mid
	for (long long i = left_level + 1; i < right_level; i++) {
		for (long long j = 0; j < i; j++) {
			answer.push_back(i);
		}
		for (long long j = i + 1; j <= long_n; j++) {
			answer.push_back(j);
		}
	}


	// last
	cnt = 0;
	for (long long i = 0; i < right_level; i++) {
		if (cnt >= long_n - right_discard) {
			break;
		}
		else {
			answer.push_back(right_level);
			cnt++;
		}
	}
	for (long long i = right_level + 1; i <= long_n; i++) {
		if (cnt >= long_n - right_discard) {
			break;
		}
		else {
			answer.push_back(i);
			cnt++;
		}
	}
	


	return answer;

}

int main() {
	vector<int> result = solution(4, 5, 5);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << endl;
	}
	//solution(4, 0, 0);


}