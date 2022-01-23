#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
constexpr auto MAX_SIZE = 1001; 

using namespace std;

vector<int> map[MAX_SIZE];
bool visited[MAX_SIZE];

void DFS(int start) {
	visited[start] = true;
	cout << start << " ";
	for (int index = 0; index < map[start].size(); index++) {
		int next = map[start][index];
		if (!visited[next]) {
			DFS(next);
		}
	}
}

void BFS(int start) {
	queue<int> next_que;
	next_que.push(start);
	visited[start] = true;

	while (!next_que.empty()) {
		int current = next_que.front();
		next_que.pop();
		cout << current << " ";
		for (int index = 0; index < map[current].size(); index++) {
			int next_ver = map[current][index];
			if (!visited[next_ver]) {
				next_que.push(next_ver);
				visited[next_ver] = true;
			}
		}
	}
}

int main() {
	int N, M, V;

	cin >> N >> M >> V;

	for (int index = 1; index <= N; index++) {
		// initialize visited
		visited[index] = false;
	}

	int u, v;
	for (int count = 0; count < M; count++) {
		cin >> u >> v;
		map[u].push_back(v);
		map[v].push_back(u);
	}
	for (int index = 1; index <= N; index++) {
		sort(map[index].begin(), map[index].end());
	}

	DFS(V);
	cout << endl;

	for (int index = 1; index <= N; index++) {
		// initialize visited
		visited[index] = false;
	}
	BFS(V);
	cout << endl;
}