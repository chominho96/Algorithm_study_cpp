#include <iostream>
#define MAX_SIZE 101

using namespace std;

int MAP[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];

int dx[]{ 0, 0, 1, -1 };
int dy[]{ 1, -1, 0, 0 };

bool isRoute(int row, int col, int row_size, int col_size) {
	if (row >= 0 && row < row_size && col >= 0 && col < col_size) {
		return true;
	}
	return false;
}


void DFS(int row, int col, int row_size, int col_size) {
	visited[row][col] = true;
	MAP[row][col] = -1;
	// -1 means air
	// air-- each step

	for (int count = 0; count < 4; count++) {
		int next_row = row + dx[count];
		int next_col = col + dy[count];

		if (isRoute(next_row, next_col, row_size, col_size) && !visited[next_row][next_col] && MAP[next_row][next_col] == 0) {
			DFS(next_row, next_col, row_size, col_size);
		}
	}
}

bool isContactAir(int row, int col, int row_size, int col_size, int air) {
	for (int count = 0; count < 4; count++) {
		int next_row = row + dx[count];
		int next_col = col + dy[count];
		
		if (isRoute(next_row, next_col, row_size, col_size) && (MAP[next_row][next_col] >= air && MAP[next_row][next_col] < 0)) {
			return true;
		}
	}
	return false;
}

void makeAirDFS(int row, int col, int row_size, int col_size, int air) {
	MAP[row][col] = air;
	visited[row][col] = true;
	for (int count = 0; count < 4; count++) {
		int next_row = row + dx[count];
		int next_col = col + dy[count];

		if (isRoute(next_row, next_col, row_size, col_size) && !visited[next_row][next_col] && MAP[next_row][next_col] == 0) {
			makeAirDFS(next_row, next_col, row_size, col_size, air);
		}
	}
}


int main() {
	int row, col, input_num, final_cheese_num;
	int result = 0;
	int cheese_num = 0;

	int air = -1;

	cin >> row >> col;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> input_num;
			MAP[i][j] = input_num;
			
			if (input_num == 1) {
				cheese_num++;
			}

			visited[i][j] = false;
		}
	}

	DFS(0, 0, row, col);


	while (cheese_num != 0) {
		final_cheese_num = cheese_num;
		result++;

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (MAP[i][j] == 1 && isContactAir(i, j, row, col, air)) {
					makeAirDFS(i, j, row, col, air - 1);
					cheese_num--;

				}
			}
		}

		air--;
	}

	cout << result << endl << final_cheese_num << endl;
	
	



}