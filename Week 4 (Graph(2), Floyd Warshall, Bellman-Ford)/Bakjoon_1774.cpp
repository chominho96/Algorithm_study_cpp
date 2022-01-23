#include <iostream>
#include <queue>
#include <iomanip>
#include <cmath>
#define MAX_SIZE 1001

using namespace std;

struct edge {
	int start;
	int end;
	double weight = -1;
};

struct coordinate {
	int x;
	int y;
};

struct compare {
	bool operator()(edge e_1, edge e_2) {
		return e_1.weight > e_2.weight;
	}
};

bool visited[MAX_SIZE];
edge MAP[MAX_SIZE][MAX_SIZE];
coordinate vertex_lst[MAX_SIZE];

double Prim(int size) {
	double result = 0;

	priority_queue<edge, vector<edge>, compare> que;

	for (int index = 2; index <= size; index++) {
		que.push(MAP[1][index]);
	}
	
	visited[1] = true;

	while (!que.empty()) {
		edge current = que.top();
		que.pop();

		if (!visited[current.end]) {
			result += current.weight;
			visited[current.end] = true;
		}

		for (int i = 1; i <= size; i++) {
			if (!visited[MAP[current.end][i].end]) {
				que.push(MAP[current.end][i]);
			}
		}
	}
	
	return result;
}


int main() {
	int N, M, x, y;

	cin >> N >> M;

	for (int index = 1; index <= N; index++) {
		cin >> x >> y;
		vertex_lst[index] = coordinate{ x, y };
	}

	for (int count = 0; count < M; count++) {
		cin >> x >> y;
		MAP[x][y] = edge{ x, y, 0 };
		MAP[y][x] = edge{ y, x, 0 };
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (MAP[i][j].weight == -1) {
				double result_weight = sqrt(pow(double(vertex_lst[i].x) - double(vertex_lst[j].x), 2) + pow(double(vertex_lst[i].y) - double(vertex_lst[j].y), 2));
				MAP[i][j].start = i;
				MAP[i][j].end = j;
				MAP[i][j].weight = result_weight;

				MAP[j][i].start = j;
				MAP[j][i].end = i;
				MAP[j][i].weight = result_weight;
			}
			
		}
	}
	cout << fixed;
	cout.precision(2);

	cout << Prim(N) << endl;


}