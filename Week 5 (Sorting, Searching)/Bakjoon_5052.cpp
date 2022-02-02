#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int T, N;
	string input_str;

	cin >> T;


	for (int count = 0; count < T; count++) {
		vector<string> phone_number[10][11];

		cin >> N;
		for (int index = 0; index < N; index++) {
			cin >> input_str;
			phone_number[int(input_str[0] - '0')][input_str.length()].push_back(input_str);
		}

		bool flag = true;

		for (int index = 0; index < 10; index++) {
			if (flag) {
				for (int length_index = 1; length_index <= 10; length_index++) {
					if (flag) {
						sort(phone_number[index][length_index].begin(), phone_number[index][length_index].end());
						for (int i = 0; i < phone_number[index][length_index].size(); i++) {
							if (flag) {
								string current = phone_number[index][length_index][i];

								for (int j = length_index + 1; j <= 10; j++) {
									if (flag) {
										for (int k = 0; k < phone_number[index][j].size(); k++) {
											string next = phone_number[index][j][k];
											string next_result = "";
											// make string that has same length
											for (int str_index = 0; str_index < current.size(); str_index++) {
												next_result += next[str_index];
											}

											if (next_result == current) {
												flag = false;
												break;
											}

										}
									}
									else {
										break;
									}
									
								}
							}
							else {
								break;
							}
						}
					}
					else {
						break;
					}
				}
			}
			else {
				break;
			}
		}

		if (flag) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}



	}


}