#include <iostream>
#include <cmath>
#define MAX_SIZE 16
#define MAX_DIAGONAL 1000

using namespace std;

bool width[MAX_SIZE];
bool height[MAX_SIZE];
bool left_diagonal[MAX_DIAGONAL];
bool right_diagonal[MAX_DIAGONAL];

int result = 0;

inline bool canGo(const int& row, const int& col, const int& max_size) {
	return !width[row] && !height[col] && !left_diagonal[row + col - 1] && !right_diagonal[(row - col > 0 ? row - col : (col - row) + max_size)];
}


void find(const int& current_index, const int& current_size, const int& max_size) {
	// end condtion
	if (current_size == max_size) {
		result++;
		return;
	}

	int next_level;
	
	if (current_index % max_size == 0) {
		next_level = (current_index / max_size) * max_size + 1;
	}
	else {
		next_level = (current_index / max_size + 1) * max_size + 1;
	}

	// go next
	for (int index = next_level; index < next_level + max_size; index++) {

		int row, col;

		// calculate ( row, col )
		if (index % max_size == 0) {
			row = index / max_size;
			col = max_size;
		}
		else {
			row = index / max_size + 1;
			col = index % max_size;
		}

		// check and go
		if (canGo(row, col, max_size)) {
			// On
			width[row] = true;
			height[col] = true;
			left_diagonal[row + col - 1] = true;
			right_diagonal[(row - col > 0 ? row - col : (col - row) + max_size)] = true;
			// recursion
			find(index, current_size + 1, max_size);
			// Off
			width[row] = false;
			height[col] = false;
			left_diagonal[row + col - 1] = false;
			right_diagonal[(row - col > 0 ? row - col : (col - row) + max_size)] = false;
		}
	}

}

int main() {
	int N;
	cin >> N;
	
	for (int index = 1; index <= N; index++) {
		int row, col;

		// calculate ( row, col )
		if (index % N == 0) {
			row = index / N;
			col = N;
		}
		else {
			row = index / N + 1;
			col = index % N;
		}
		// On
		width[row] = true;
		height[col] = true;
		left_diagonal[row + col - 1] = true;
		right_diagonal[(row - col > 0 ? row - col : (col - row) + N)] = true;
		find(index, 1, N);
		// Off
		width[row] = false;
		height[col] = false;
		left_diagonal[row + col - 1] = false;
		right_diagonal[(row - col > 0 ? row - col : (col - row) + N)] = false;


	}

	cout << result << endl;
}