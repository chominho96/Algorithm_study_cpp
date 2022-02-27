#include <iostream>
#include <queue>
#define MAX_SIZE 100001
#define MAX_STATION_SIZE 1001
#define INF 9999999

using namespace std;

vector<int> MAP[MAX_SIZE];
// Hyper Tube number that each vertex has
vector<int> HYPER_TUBE[MAX_STATION_SIZE];
// station number that each hyper tube has
int dist[MAX_SIZE];
bool visited[MAX_STATION_SIZE];

bool success = false;


void BFS(const int& max_size) {
	queue<int> vertex;

	dist[1] = 1;

	vertex.push(1);

	while (!vertex.empty()) {
		int current_vertex = vertex.front();
		vertex.pop();

		for (int i = 0; i < MAP[current_vertex].size(); i++) {
			int tube = MAP[current_vertex][i];

			// 1. tube visit
			if (!visited[tube]) {
				visited[tube] = true;
				
				// 2. update dist
				for (int j = 0; j < HYPER_TUBE[tube].size(); j++) {
					int next_vertex = HYPER_TUBE[tube][j];
					if (dist[next_vertex] == INF) {
						dist[next_vertex] = dist[current_vertex] + 1;
					}
					// push next vertex to queue
					vertex.push(next_vertex);
					// end condition
					if (next_vertex == max_size) {
						return;
					}
				}
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K, M, station;

	cin >> N >> K >> M;

	// initialize
	for (int index = 2; index <= N; index++) {
		dist[index] = INF;
	}

	for (int index = 1; index <= M; index++) {
		for (int i = 0; i < K; i++) {
			cin >> station;
			MAP[station].push_back(index);
			HYPER_TUBE[index].push_back(station);
		}
	}

	BFS(N);

	if (dist[N] == INF) {
		cout << -1 << endl;
	}
	else {
		cout << dist[N] << endl;
	}
}