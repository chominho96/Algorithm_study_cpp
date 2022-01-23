#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct row_col {
	int row;
	int col;
};

int map[101][101];
bool visited[101][101];

int dx[4]{ 1, 0, -1, 0 };
int dy[4]{ 0, 1, 0, -1 };


void BFS(int N, int M) {
	queue<row_col> route;
	visited[1][1] = true;
	route.push(row_col{ 1, 1 });

	while (!route.empty()) {
		row_col current = route.front();
		route.pop();
		
		for (int i = 0; i < 4; i++) {
			int next_row = current.row + dx[i];
			int next_col = current.col + dy[i];
			if (next_row >= 1 && next_row <= N && next_col >= 1 && next_col <= M && map[next_row][next_col] != 0) {
				// if it is route
				if (!visited[next_row][next_col]) {
					route.push(row_col{ next_row, next_col });
					visited[next_row][next_col] = true;
				}
				if (map[next_row][next_col] == 1 || map[next_row][next_col] > map[current.row][current.col] + 1) {
					map[next_row][next_col] = map[current.row][current.col] + 1;
				}
			}
		}
	}
	
}


int main() {
	int N, M;
	
	cin >> N >> M;
	
	// initialize visited
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			visited[i][j] = false;
		}
	}

	string elem;
	for (int row = 1; row <= N; row++) {
		cin >> elem;
		for (int col = 1; col <= M; col++) {
			map[row][col] = int(elem[col - 1] - '0');
		}
	}
	BFS(N, M);
	cout << map[N][M] << endl;
}