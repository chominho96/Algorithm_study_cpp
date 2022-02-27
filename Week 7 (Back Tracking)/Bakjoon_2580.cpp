#include <iostream>
#include <vector>
#include <string>
#define MAX_SIZE 10

using namespace std;

struct row_col {
	int row;
	int col;
};

int MAP[MAX_SIZE][MAX_SIZE];
bool width[MAX_SIZE][MAX_SIZE];
bool height[MAX_SIZE][MAX_SIZE];
bool block[MAX_SIZE][MAX_SIZE];
vector<row_col> blank;

inline bool canWidth(const int& target_width, const int& target_num) {
	return !width[target_width][target_num];
}
inline bool canHeight(const int& target_height, const int& target_num) {
	return !height[target_height][target_num];
}
inline bool canBlock(const int& target_block, const int& target_num) {
	return !block[target_block][target_num];
}
int getBlockIndex(int i, int j) {
	if (i <= 3) {
		if (j <= 3) {
			return 1;
		}
		else if (j <= 6) {
			return 2;
		}
		else {
			return 3;
		}
	}
	else if (i <= 6) {
		if (j <= 3) {
			return 4;
		}
		else if (j <= 6) {
			return 5;
		}
		else {
			return 6;
		}
	}
	else {
		if (j <= 3) {
			return 7;
		}
		else if (j <= 6) {
			return 8;
		}
		else {
			return 9;
		}
	}
}

bool canGo(int i, int j, int number) {
	return canWidth(i, number) && canHeight(j, number) && canBlock(getBlockIndex(i, j), number);
}

bool flag = false;

void sudoku(int index) {
	// end condition
	if (index == blank.size()) {
		flag = true;
		return;
	}
	int i = blank[index].row;
	int j = blank[index].col;
	// find next position
	for (int next_index = 1; next_index < MAX_SIZE; next_index++) {
		if (canGo(i, j, next_index)) {
			MAP[i][j] = next_index;
			// On
			width[i][next_index] = true;
			height[j][next_index] = true;
			block[getBlockIndex(i, j)][next_index] = true;
			// recursion
			sudoku(index + 1);
			// Off
			
			if (flag) {
				return;
			}
			
			width[i][next_index] = false;
			height[j][next_index] = false;
			block[getBlockIndex(i, j)][next_index] = false;
		}
	}
}


int main() {
	int input_num;


	// input, initialize
	for (int i = 1; i < MAX_SIZE; i++) {
		for (int j = 1; j < MAX_SIZE; j++) {
			cin >> input_num;
			MAP[i][j] = input_num;
			if (input_num == 0) {
				blank.push_back(row_col{ i, j });
			}
			else {
				width[i][input_num] = true;
				height[j][input_num] = true;
				block[getBlockIndex(i, j)][input_num] = true;
			}
		}
	}


	sudoku(0);

	for (int i = 1; i < MAX_SIZE; i++) {
		for (int j = 1; j < MAX_SIZE; j++) {
			cout << MAP[i][j] << " ";
		}
		cout << "\n";
	}
	
}