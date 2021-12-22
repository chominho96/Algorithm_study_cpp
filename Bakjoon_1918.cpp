#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

string calc_no_bracket(const vector<string>& vec) {
	// calculation expression which doesn't have bracket

	stack<string> result_st;

	for (int index = 0; index < vec.size(); index++) {
		if (vec[index] == "*" || vec[index] == "/") {
			string str_1 = result_st.top();
			result_st.pop();
			result_st.push(str_1 + vec[index + 1] + vec[index]);
			index++;
		}

		else {
			string str1;
			str1 += vec[index];
			result_st.push(str1);
		}
	}

	// dispose of '+' and '-'
	string result;

	while (result_st.size() != 1) {
		string str_1 = result_st.top();
		result_st.pop();
		string op = result_st.top();
		result_st.pop();

		result = str_1 + op + result;
	}
	result = result_st.top() + result;

	return result;
}


int main() {
	string s;
	cin >> s;

	stack<string> st;

	for (int index = 0; index < s.length(); index++) {
		// case 1 : ')'
		if (s[index] == ')') {
			vector<string> v;

			while (true) {
				string str_in_st = st.top();
				st.pop();

				if (str_in_st == "(") {
					break;
				}
				else {
					v.push_back(str_in_st);
				}
			}
			reverse(v.begin(), v.end());

			st.push(calc_no_bracket(v));
		}

		// case 2 : just push
		else {
			string str;
			str += s[index];
			st.push(str);
		}
	}


	vector<string> result;
	while (!st.empty()) {
		result.push_back(st.top());
		st.pop();
	}

	reverse(result.begin(), result.end());

	cout << calc_no_bracket(result) << endl;

}