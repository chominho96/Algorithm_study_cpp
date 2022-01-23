#include <iostream>
#include <vector>
#include <algorithm>
constexpr auto MAX_SIZE = 100001;
constexpr auto INF = -1;

using namespace std;

struct ver_val {
	int vertex;
	short value;
};

vector<ver_val> MAP[MAX_SIZE];
vector<long long> visited;
// indicated whether it is visited node and store max value

void DFS(int cur_node) {
	for (int index = 0; index < MAP[cur_node].size(); index++) {
		ver_val next_node = MAP[cur_node][index];

		if (visited[next_node.vertex] == INF) {
			// if it is not visited node
			visited[next_node.vertex] = visited[cur_node] + next_node.value;
			// update child node's value and store the data at visited
			DFS(next_node.vertex);
		}
	}
}

int main() {
	int V;
	cin >> V;

	visited.reserve(V + 1);
	visited.push_back(0);
	// dummy value : not use index 0

	int cur_ver, next_ver;
	short value;
	for (int index = 1; index <= V; index++) {
		visited.push_back(-1);
		// initialize visited

		cin >> cur_ver;
		while (true) {
			cin >> next_ver;
			if (next_ver == -1) {
				break;
			}
			else {
				cin >> value;
				MAP[cur_ver].push_back(ver_val{ next_ver, value });
			}
		}
	}

	// step 1 : find the longest route from vertex 1
	int result_vertex = 0;
	visited[1] = 0;
	DFS(1);
	result_vertex = max_element(visited.begin(), visited.end()) - visited.begin();

	// step 2 : find the longest route from vertex which is found by step 1
	for (int index = 1; index <= V; index++) {
		visited[index] = INF;
	}
	visited[result_vertex] = 0;
	DFS(result_vertex);
	
	// step 3 : print
	cout << *max_element(visited.begin(), visited.end()) << endl;
	
}