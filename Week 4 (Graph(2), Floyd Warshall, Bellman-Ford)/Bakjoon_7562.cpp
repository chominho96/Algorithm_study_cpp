#include <iostream>
#include <vector>
#include <queue>
#define MAX_SIZE 300

using namespace std;

int MAP[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];
int dx[]{ 1, 1, 2, 2, -1, -1, -2, -2 };
int dy[]{ 2, -2, 1, -1, 2, -2, 1, -1 };

queue<int> row_que;
queue<int> col_que;

bool isRoute(int i, int j, int size) {
	if (i >= 0 && i < size && j >= 0 && j < size) {
		return true;
	}
	return false;
}

void BFS(int start_row, int start_col, int size, int end_row, int end_col) {
	
	row_que.push(start_row);
	col_que.push(start_col);
	visited[start_row][start_col] = true;

	while (!row_que.empty()) {
		int current_row = row_que.front();
		int current_col = col_que.front();
		row_que.pop();
		col_que.pop();

		if (current_row == end_row && current_col == end_col) {
			break;
		}
		else {
			for (int count = 0; count < 8; count++) {
				int next_row = current_row + dx[count];
				int next_col = current_col + dy[count];
				if (isRoute(next_row, next_col, size) && !visited[next_row][next_col]) {
					MAP[next_row][next_col] = MAP[current_row][current_col] + 1;
					visited[next_row][next_col] = true;

					row_que.push(next_row);
					col_que.push(next_col);
				}
			}
		}
	}

}

void initialize() {
	for (int i = 0; i < MAX_SIZE; i++) {
		for (int j = 0; j < MAX_SIZE; j++) {
			visited[i][j] = false;
			MAP[i][j] = -1;
			// -1 means not visited
		}
	}
	while (!row_que.empty()) {
		row_que.pop();
		col_que.pop();
	}
	
}

int main() {
	int T, I, s_row, s_col, e_row, e_col;

	cin >> T;

	initialize();

	for (int count = 0; count < T; count++) {
		cin >> I >> s_row >> s_col >> e_row >> e_col;
		MAP[s_row][s_col] = 0;

		BFS(s_row, s_col, I, e_row, e_col);
		cout << MAP[e_row][e_col] << endl;

		initialize();
	}
}