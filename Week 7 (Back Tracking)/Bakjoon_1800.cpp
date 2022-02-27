#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX_SIZE 1001
#define INF 99999999

using namespace std;

vector<int> edge;

int MAP[MAX_SIZE][MAX_SIZE];
int dist[MAX_SIZE];
bool visited[MAX_SIZE];

int N, K, P;
int result = INF;

struct vertex_value {
	int vertex;
	int value;
};

void initialize() {
	for (int i = 1; i <= N; i++) {
		visited[i] = false;
		dist[i] = INF;
	}
}

bool BFS() {
	queue<int> que;
	que.push(1);
	dist[1] = 0;
	visited[1] = true;
	
	while (!que.empty()) {
		int current = que.front();
		que.pop();

		// it needs more than K edges to go to vertex N
		if (dist[current] + 1 > K) {
			return false;
		}

		for (int index = 1; index <= N; index++) {
			if (!visited[index] && MAP[current][index] != INF) {
				// end condition
				if (index == N) {
					// it needs less than K edges to go to vertex N
					// so, result is 0
					return true;
				}
				dist[index] = dist[current] + 1;
				visited[index] = true;
				que.push(index);

			}
		}
	}
	return false;
}

int getMinIndex() {
	int min = INF;
	int result_index = -1;

	for (int index = 1; index <= N; index++) {
		if (!visited[index] && dist[index] < min) {
			min = dist[index];
			result_index = index;
		}
	}

	return result_index;
}

void dijkstra() {
	int start = 0;
	int end = P - 1;

	while (start <= end) {
		int target = edge[(start + end) / 2];

		visited[1] = true;
		dist[1] = 0;

		for (int i = 2; i <= N; i++) {
			if (MAP[1][i] == INF) {
				dist[i] = INF;
			}
			else if (MAP[1][i] <= target) {
				dist[i] = 0;
			}
			else {
				dist[i] = 1;
			}
		}

		// main logic
		for (int count = 0; count < N - 2; count++) {
			int current_index = getMinIndex();

			// cannot find route
			if (current_index == -1) {
				break;
			}

			visited[current_index] = true;
			
			for (int i = 1; i <= N; i++) {
				if (!visited[i] && MAP[current_index][i] != INF) {
					if (MAP[current_index][i] > target && dist[i] > dist[current_index] + 1) {
						dist[i] = dist[current_index] + 1;
					}
					else if (MAP[current_index][i] <= target && dist[i] > dist[current_index]) {
						dist[i] = dist[current_index];
					}
				}
			
			}
		}

		// binary search
		if (dist[N] <= K) {
			if (result > target) {
				result = target;
			}
			end = (start + end) / 2 - 1;
		}
		else {
			start = (start + end) / 2 + 1;
		}
		initialize();
	}

}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b, value;
	cin >> N >> P >> K;

	edge.reserve(P);

	// initialize
	for (int i = 1; i <= N; i++) {
		dist[i] = INF;
		for (int j = 1; j <= N; j++) {
			MAP[i][j] = INF;
		}
	}

	// input
	for (int count = 0; count < P; count++) {
		cin >> a >> b >> value;
		MAP[a][b] = value;
		MAP[b][a] = value;
		edge.push_back(value);
	}

	// sort edge vec
	sort(edge.begin(), edge.end());

	// check whether it needs less than K edges
	if (BFS()) {
		cout << 0 << endl;
		return 0;
	}
	else {
		initialize();
	}

	// binary search and dijkstra
	dijkstra();

	if (result == INF) {
		cout << -1 << endl;
	}
	else {
		cout << result << endl;
	}
	

	
}