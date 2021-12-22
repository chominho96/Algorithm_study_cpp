#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	int T;
	cin >> T;
	
	string input;
	for (int count = 0; count < T; count++) {
		stack<char> bracket;

		bool flag = false;
		cin >> input;

		for (int index = 0; index < input.size(); index++) {
			if (input[index] == '(') {
				bracket.push('(');
			}
			else {
				if (bracket.empty()) {
					cout << "NO" << endl;
					flag = true;
					break;
				}
				else {
					bracket.pop();
				}
			}
		}

		if (!flag) {
			if (!bracket.empty()) {
				cout << "NO" << endl;
			}
			else {
				cout << "YES" << endl;
			}
		}
	}
}