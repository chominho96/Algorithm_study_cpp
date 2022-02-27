#include <iostream>
#include <queue>
#include <string>
#define MAX_SIZE 51

using namespace std;

bool visited[MAX_SIZE][MAX_SIZE];
int MAP[MAX_SIZE][MAX_SIZE];

int dx[]{ 0, 0, 1, -1 };
int dy[]{ 1, -1, 0, 0 };

int result = 0;

void initialize(int N, int M) {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			visited[i][j] = false;
		}
	}
}

inline bool isRoute(int row, int col, int N, int M) {
	return row >= 1 && row <= N && col >= 1 && col <= M;
}

void BFS(int row, int col, int N, int M) {
	queue<int> row_que;
	queue<int> col_que;

	queue<int> result_row;
	queue<int> result_col;

	row_que.push(row);
	col_que.push(col);
	result_row.push(row);
	result_col.push(col);

	visited[row][col] = true;

	int min_wall = 10;

	while (!row_que.empty()) {
		int current_row = row_que.front();
		int current_col = col_que.front();

		row_que.pop();
		col_que.pop();

		for (int count = 0; count < 4; count++) {
			int next_row = current_row + dx[count];
			int next_col = current_col + dy[count];

			if (!isRoute(next_row, next_col, N, M)) {

				initialize(N, M);
				return;
			}
			else if (!visited[next_row][next_col]) {
				if (MAP[next_row][next_col] <= MAP[row][col]) {
					row_que.push(next_row);
					col_que.push(next_col);


					visited[next_row][next_col] = true;
					
					result_row.push(next_row);
					result_col.push(next_col);
				}
				else {
					if (MAP[next_row][next_col] < min_wall) {
						min_wall = MAP[next_row][next_col];
					}
				}
			}
		}
	}
	
	if (min_wall != 10) {

		while (!result_row.empty()) {
			int current_row = result_row.front();
			int current_col = result_col.front();

			result_row.pop();
			result_col.pop();

			

			result += (min_wall - MAP[current_row][current_col]);
			MAP[current_row][current_col] = min_wall;

		}
	}
	
	
	

	initialize(N, M);
}

int main() {
	int N, M;
	cin >> N >> M;

	string input_str;

	// input and initialize
	for (int i = 1; i <= N; i++) {
		cin >> input_str;
		for (int j = 1; j <= M; j++) {
			MAP[i][j] = input_str[j - 1] - '0';
		}
	}

	for (int i = 2; i < N; i++) {
		for (int j = 2; j < M; j++) {
			BFS(i, j, N, M);
		}
	}

	cout << result << endl;
}