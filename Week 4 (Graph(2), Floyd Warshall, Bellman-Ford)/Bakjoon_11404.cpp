#include <iostream>
#define MAX_SIZE 101
#define INF 99999999999

using namespace std;

long long MAP[MAX_SIZE][MAX_SIZE];

void floydWarshall(int size) {
	for (int k = 1; k <= size; k++) {
		for (int i = 1; i <= size; i++) {
			for (int j = 1; j <= size; j++) {
				if (i != j && MAP[i][k] + MAP[k][j] < MAP[i][j]) {
					MAP[i][j] = MAP[i][k] + MAP[k][j];
				}
				
				
			}
		}
	}

	for (int i = 1; i <= size; i++) {
		for (int j = 1; j <= size; j++) {
			if (i == j) {
				cout << 0 << " ";
			}
			else if (MAP[i][j] == INF) {
				cout << 0 << " ";
			}
			else {
				cout << MAP[i][j] << " ";
			}
		}
		cout << "\n";
	}
}

int main() {
	int n, m;
	long long start, end, weight;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			MAP[i][j] = INF;
		}
	}


	for (int count = 0; count < m; count++) {
		cin >> start >> end >> weight;
		if (MAP[start][end] > weight) {
			MAP[start][end] = weight;
		}
	}

	floydWarshall(n);
}