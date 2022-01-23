#include <iostream>
#include <string>
#include <queue>
#define MAX_SIZE 1001

using namespace std;

struct state {
	int row;
	int col;
	bool broke_wall;
};

struct map {
	int value;
	int dist_not_broke;
	int dist_broke;
};

map MAP[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE][2];
// 0 : not broke wall CASE
// 1 : broke wall CASE

int dx[]{ 0, 0, 1, -1 };
int dy[]{ 1, -1, 0, 0 };

bool isRoute(int row, int col, int row_size, int col_size) {
	if (row >= 1 && row <= row_size && col >= 1 && col <= col_size) {
		return true;
	}
	return false;
}

int BFS(int row_size, int col_size) {
	queue<state> state_que;

	state_que.push(state{ 1, 1, false });


	visited[1][1][0] = true;

	while (!state_que.empty()) {
		state current = state_que.front();
		state_que.pop();

		if (current.row == row_size && current.col == col_size) {
			if (visited[current.row][current.col][0]) {
				return MAP[current.row][current.col].dist_not_broke;
			}
			else {
				return MAP[current.row][current.col].dist_broke;
			}
			
		}

		for (int count = 0; count < 4; count++) {
			int next_row = current.row + dx[count];
			int next_col = current.col + dy[count];

			if (isRoute(next_row, next_col, row_size, col_size)) {
				// if it is route
				if (current.broke_wall && MAP[next_row][next_col].value == 0 && !visited[next_row][next_col][1]) {
					// already broke wall and next location is not visited non-wall route
					MAP[next_row][next_col].dist_broke = MAP[current.row][current.col].dist_broke + 1;
					visited[next_row][next_col][1] = true;
					state_que.push(state{ next_row, next_col, true });
				}
				else if (!current.broke_wall) {
					// not broke wall yet
					if (MAP[next_row][next_col].value == 0 && !visited[next_row][next_col][0]) {
						// next location is not visited wall route
						MAP[next_row][next_col].dist_not_broke = MAP[current.row][current.col].dist_not_broke + 1;
						visited[next_row][next_col][0] = true;
						state_que.push(state{ next_row, next_col, false });
					}
					else if (MAP[next_row][next_col].value == 1 && !visited[next_row][next_col][1]) {
						// next location is not visited non-wall route
						MAP[next_row][next_col].dist_broke = MAP[current.row][current.col].dist_not_broke + 1;
						visited[next_row][next_col][1] = true;
						state_que.push(state{ next_row, next_col, true });
					}
				}
			}
		}
	}

	return -1;
}

int main() {
	int N, M;
	cin >> N >> M;

	string input_str;

	for (int i = 1; i <= N; i++) {
		cin >> input_str;
		for (int j = 1; j <= M; j++) {
			MAP[i][j] = map{ int(input_str[j - 1] - '0'), 1, 0 };
		}
	}

	cout << BFS(N, M) << endl;
}