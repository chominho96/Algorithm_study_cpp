#include <iostream>
#include <string>
#define MAX_SIZE 987654322

using namespace std;

//bool visited[MAX_SIZE];

string min_str = "987654322";
string max_str = "0";

void find(string sign, string current, int target) {
	// exit condition
	for (int index = 0; index < current.size(); index++) {
		if (current[index] - '0' == target) {
			return;
		}
	}

	string next = current + to_string(target);
	if (next.size() == sign.size() + 1) {
		if (next < min_str) {
			min_str = next;
		}
		if (next > max_str) {
			max_str = next;
		}
		return;
	}

	if (sign[next.size() - 1] == '<') {
		for (int count = target + 1; count <= 9; count++) {
			find(sign, next, count);
		}
	}
	else {
		for (int count = target - 1; count >= 0; count--) {
			find(sign, next, count);
		}
	}
}

int main() {
	int k;
	char input_char;
	cin >> k;
	
	string sign = "";
	for (int count = 0; count < k; count++) {
		cin >> input_char;
		sign += input_char;
	}

	for (int count = 0; count <= 9; count++) {
		find(sign, "", count);
	}

	cout << max_str << "\n" << min_str << "\n";
}
