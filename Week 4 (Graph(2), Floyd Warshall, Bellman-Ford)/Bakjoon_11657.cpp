#include <iostream>
#include <vector>
#define MAX_SIZE 501
#define INF 99999999

using namespace std;

int MAP[MAX_SIZE][MAX_SIZE];
long long dist[MAX_SIZE];


void Bellman_Ford(int size) {
	dist[1] = 0;
	
	// repeat (V - 1) times
	for (int count = 0; count < size - 1; count++) {
		// for all edges
		for (int i = 1; i <= size; i++) {
			int start = i;
			
			if (dist[start] == INF) {
				continue;
			}

			for (int j = 1; j <= size; j++) {
				int end = j;
				// for (i, j) edge

				// if it is not edge or it is not discovered vertex
				if (MAP[start][end] == INF) {
					continue;
				}
			
				
				if (dist[start] + MAP[start][end] < dist[end]) {
					dist[end] = dist[start] + MAP[start][end];
				}

			}
		}
	}

	// check if it has cycle
	// for all edges
	for (int i = 1; i <= size; i++) {
		int start = i;

		if (dist[start] == INF) {
			continue;
		}

		for (int j = 1; j <= size; j++) {
			int end = j;
			// for (i, j) edge

			// if it is not edge or it is not discovered vertex
			if (MAP[start][end] == INF) {
				continue;
			}

			if (dist[start] + MAP[start][end] < dist[end]) {
				cout << -1 << endl;
				return;
			}

		}
	}

	for (int index = 2; index <= size; index++) {
		if (dist[index] == INF) {
			cout << -1 << endl;
		}
		else {
			cout << dist[index] << endl;
		}
		
	}

}

int main() {
	int N, M, A, B, C;

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			MAP[i][j] = INF;
		}
		dist[i] = INF;
	}

	for (int count = 0; count < M; count++) {
		cin >> A >> B >> C;

		if (MAP[A][B] > C) {
			MAP[A][B] = C;
		}

	}

	Bellman_Ford(N);
}