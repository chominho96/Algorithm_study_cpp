#include <iostream>
#include <queue>

using namespace std;

bool visited[1000001];
// not use index 0

struct index_value {
	// store value's index and value
	int index;
	int value;
};

struct compare_max {
	// compare funciton that check bigger value
	bool operator()(const index_value& s1, const index_value& s2) {
		return s1.value <= s2.value;
	}
};
struct compare_min {
	// compare funciton that check smaller value
	bool operator()(const index_value& s1, const index_value& s2) {
		return s1.value >= s2.value;
	}
};



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	int t, c;
	int input_int;
	char input_char;

	cin >> t;

	for (int index = 0; index < 1000000; index++) {
		// initialize visited
		visited[index] = true;
	}

	for (int count = 0; count < t; count++) {
		int size = 0;
		// use visited array to check if the value is already used

		priority_queue<index_value, vector<index_value>, compare_max> max;
		priority_queue<index_value, vector<index_value>, compare_min> min;

		cin >> c;
		

		for (int inner_count = 0; inner_count < c; inner_count++) {
			cin >> input_char >> input_int;

			if (input_char == 'I') {
				// 1. input
				// just push to each queue with its index
				max.push({ ++size, input_int });
				min.push({ size, input_int });
			}
			else {
				// 2. delete
				if (max.empty() || min.empty()) {
					// exception : check if queue is empty
					continue;
				}
				else {
					if (input_int == 1) {
					// 2-1) pop max value

						while (!max.empty()) {
							// if max queue is emtpy, quit
							index_value v = max.top();
							max.pop();
							if (visited[v.index] == false) {
								// if the index is already visited
								continue;
							}
							else {
								// indicate the index is used
								visited[v.index] = false;
								break;
							}
						}
						
					}
					else {
					// 2-1) pop min value

						while (!min.empty()) {
							// if min queue is emtpy, quit
							index_value v = min.top();
							min.pop();
							if (visited[v.index] == false) {
								// if the index is already visited
								continue;
							}
							else {
								// indicate the index is used
								visited[v.index] = false;
								break;
							}
						}
					}

				}

			}
		}
		// 3. Lastly, for delete used index, check if the index is used and extract real max and min value

		while (!max.empty()) {
			// 3-1) max case
			index_value v = max.top();
			if (visited[v.index] == false) {
				// already visited
				max.pop();
			}

			else {
				break;
			}
		}
		while (!min.empty()) {
			// 3-2) min case
			index_value v = min.top();
			if (visited[v.index] == false) {
				// already visited
				min.pop();
			}

			else {
				break;
			}
		}

		// print
		if (max.empty() || min.empty()) {
			cout << "EMPTY\n";
		}
		else {
			cout << max.top().value << " " << min.top().value << "\n";
		}

		for (int index = 0; index <= size; index++) {
			// initialize visited
			visited[index] = true;
		}
	}

}
