#include <iostream>
#include <queue>
#include <string>
#define MAX_SIZE 50

using namespace std;

char MAP[MAX_SIZE][MAX_SIZE];
int dist[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];

int dx[]{ 0, 0, 1, -1 };
int dy[]{ 1, -1, 0, 0 };

bool isRoute(int row, int col, int row_size, int col_size) {
	if (row >= 0 && row < row_size && col >= 0 && col < col_size && MAP[row][col] == 'L') {
		return true;
	}
	return false;
}

int BFS(int row, int col, int row_size, int col_size) {
	int result = 0;

	queue<int> row_que;
	queue<int> col_que;

	row_que.push(row);
	col_que.push(col);

	while (!row_que.empty()) {
		int current_row = row_que.front();
		int current_col = col_que.front();
		row_que.pop();
		col_que.pop();
		visited[current_row][current_col] = true;

		for (int count = 0; count < 4; count++) {
			int next_row = current_row + dx[count];
			int next_col = current_col + dy[count];

			if (isRoute(next_row, next_col, row_size, col_size) && !visited[next_row][next_col]) {
				dist[next_row][next_col] = dist[current_row][current_col] + 1;
				if (dist[next_row][next_col] > result) {
					result = dist[next_row][next_col];
				}
				row_que.push(next_row);
				col_que.push(next_col);
				visited[next_row][next_col] = true;
			}
		}
	}

	return result;
}

void initialize() {
	for (int i = 0; i < MAX_SIZE; i++) {
		for (int j = 0; j < MAX_SIZE; j++) {
			visited[i][j] = false;
			dist[i][j] = 0;
		}
	}
}

int main() {
	int row, col;
	int result = 0;
	string input_str;
	cin >> row >> col;

	for (int i = 0; i < row; i++) {
		cin >> input_str;
		for (int j = 0; j < col; j++) {
			MAP[i][j] = input_str[j];
		}
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (MAP[i][j] == 'L') {
				int BFS_result = BFS(i, j, row, col);
				if (BFS_result > result) {
					result = BFS_result;
				}
				initialize();
			}
		}
	}

	cout << result << endl;

}