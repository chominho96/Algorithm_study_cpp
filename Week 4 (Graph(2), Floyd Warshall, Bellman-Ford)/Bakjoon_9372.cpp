#include <iostream>
#include <vector>
#define MAX_SIZE 1001

using namespace std;

vector<int> MAP[MAX_SIZE];
bool visitied[MAX_SIZE];

static int result = 0;

void DFS(int start) {
	visitied[start] = true;

	for (int index = 0; index < MAP[start].size(); index++) {
		int next = MAP[start][index];

		if (!visitied[next]) {
			DFS(next);
			result++;
		}
	}
};

void initialize() {
	for (int index = 0; index < MAX_SIZE; index++) {
		MAP[index].clear();
		visitied[index] = false;
		result = 0;
	}
}

int main() {
	int T, N, M, a, b;
	cin >> T;

	initialize();

	for (int count = 0; count < T; count++) {
		cin >> N >> M;

		for (int i = 0; i < M; i++) {
			cin >> a >> b;
			MAP[a].push_back(b);
			MAP[b].push_back(a);
		}

		DFS(1);
		cout << result << endl;
		initialize();
	}

}