#include <iostream>
#include <cmath>
#define MAX_SIZE 6562
// 3^8 == 6561

using namespace std;

char MAP[MAX_SIZE][MAX_SIZE];

int dx[]{ 1, 1, 1, -1, -1, -1, 0, 0 };
int dy[]{ 0, 1, -1, 0, 1, -1, 1, -1 };

int N;

void make_star(const int& row, const int& col, const int& level) {
	// end condtion : out of bound
	if (!(row >= 1 && row <= N && col >= 1 && col <= N)) {
		return;
	}


	// last case
	if (level == 1) {
		MAP[row][col] = ' ';
		for (int count = 0; count < 8; count++) {
			MAP[row + dx[count]][col + dy[count]] = '*';
		}
		return;
	}

	int current_length = int(pow(3, level - 1));

	
	// go to lower level (left-top)
	make_star(row - 1 * current_length, col - 1 * current_length, level - 1);

	// complete make array
	for (int i = 1; i <= current_length * 3; i++) {
		for (int j = 1; j <= current_length * 3; j++) {
			if (!(i <= current_length && j <= current_length)) {
				int next_row = (i % current_length > 0 ? i % current_length : current_length);
				int next_col = (j % current_length > 0 ? j % current_length : current_length);

				MAP[i][j] = MAP[next_row][next_col];
			}
		}
	}
	// pierce the middle
	int start_row_index = row - current_length / 2;
	int start_col_index = col - current_length / 2;

	for (int i = start_row_index; i < start_row_index + current_length; i++) {
		for (int j = start_col_index; j < start_col_index + current_length; j++) {
			MAP[i][j] = ' ';
		}
	}
}

int main() {
	cin >> N;

	int level = 0;
	int temp = N;
	while (temp != 1) {
		temp /= 3;
		level++;
	}

	make_star(N / 2 + 1, N / 2 + 1, level);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << MAP[i][j];
		}
		cout << "\n";
	}


}