#include <iostream>
#include <string>
#define MAX_SIZE 1000000

using namespace std;

bool visited[MAX_SIZE];

int result = 0;
string MAP[6][6];
int dx[]{ 0, 0, 1, -1 };
int dy[]{ 1, -1, 0, 0 };

void find(int current_row, int current_col, string current) {
	// break condition
	if (current_row < 1 || current_row > 5 || current_col < 1 || current_col > 5) {
		return;
	}
	string next = current + MAP[current_row][current_col];
	
	if (next.size() == 6) {
		if (!visited[stoi(next)]) {
			visited[stoi(next)] = true;
			result++;
		}

		return;
	}

	for (int count = 0; count < 4; count++) {
		find(current_row + dx[count], current_col + dy[count], next);
	}
	
}

int main() {
	int input_num;
	
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 5; j++) {
			cin >> input_num;
			MAP[i][j] = to_string(input_num);
		}
	}

	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 5; j++) {
			for (int k = 0; k < 4; k++) {
				find(i + dx[k], j + dy[k], MAP[i][j]);
			}
		}
	}

	cout << result << "\n";
}