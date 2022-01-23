#include <iostream>
#include <queue>
#define MAX_SIZE 401
#define INF 999999

using namespace std;

int MAP[MAX_SIZE][MAX_SIZE];

void floydWarshall(int size) {

	for (int k = 1; k <= size; k++) {
		for (int i = 1; i <= size; i++) {
			for (int j = 1; j <= size; j++) {
				if (MAP[i][j] > MAP[i][k] + MAP[k][j]) {
					MAP[i][j] = MAP[i][k] + MAP[k][j];
				}
			}
		}
	}
	
}

int main() {
	int V, E, a, b, c;
	cin >> V >> E;

	for (int i = 1; i <= V; i++) {
		for (int j = 1; j <= V; j++) {
			MAP[i][j] = INF;
		}
	}

	for (int count = 0; count < E; count++) {
		cin >> a >> b >> c;
		MAP[a][b] = c;
	}

	floydWarshall(V);

	priority_queue<int, vector<int>, greater<int>> que;
	for (int i = 1; i <= V; i++) {
		que.push(MAP[i][i]);
	}

	if (que.top() == INF) {
		cout << -1 << endl;
	}
	else {
		cout << que.top() << endl;
	}

	
}