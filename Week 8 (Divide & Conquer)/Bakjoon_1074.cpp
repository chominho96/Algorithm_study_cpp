#include <iostream>
#include <cmath>

using namespace std;

int N, r, c;

void find(int level, int result, int start_row, int start_col) {
	// end condition
	if (level == 1) {
		if (start_row == r) {
			if (start_col == c) {
				cout << result << endl;
			}
			else {
				cout << result + 1 << endl;
			}
		}
		else {
			if (start_col == c) {
				cout << result + 2 << endl;
			}
			else {
				cout << result + 3 << endl;
			}
		}
		exit(0);
	}

	// find current block
	int unit = pow(2, level - 1);
	int row_diff = r - start_row;
	int col_diff = c - start_col;

	if (row_diff < unit && col_diff < unit) {
		find(level - 1, result, start_row, start_col);
	}
	else if (row_diff < unit && col_diff >= unit) {
		find(level - 1, result + pow(pow(2, level - 1), 2), start_row, start_col + pow(2, level - 1));
	}
	else if (row_diff >= unit && col_diff < unit) {
		find(level - 1, result + pow(pow(2, level - 1), 2) * 2, start_row + pow(2, level - 1), start_col);
	}
	else {
		// r >= unit && c >= unit
		find(level - 1, result + pow(pow(2, level - 1), 2) * 3, start_row + pow(2, level - 1), start_col + pow(2, level - 1));
	}
	
	
}

int main() {
	cin >> N >> r >> c;
	r++;
	c++;

	find(N, 0, 1, 1);
}