#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX_SIZE 100001

using namespace std;

struct vertex_value {
	int vertex;
	int value;
};

struct compare {
	bool operator()(vertex_value v_1, vertex_value v_2) {
		return v_1.value > v_2.value;
	}
};

priority_queue<vertex_value, vector<vertex_value>, compare> dist;

int result = 0;
int max_edge = 0;

vector<vertex_value> MAP[MAX_SIZE];
bool visited[MAX_SIZE];

void prim(int vertex) {
	visited[vertex] = true;
	
	// edge push
	for (int index = 0; index < MAP[vertex].size(); index++) {
		if (!visited[MAP[vertex][index].vertex]) {
			dist.push(MAP[vertex][index]);
		}
	}

	while (!dist.empty()) {
		vertex_value current = dist.top();
		dist.pop();

		if (!visited[current.vertex]) {
			result += current.value;
			if (max_edge < current.value) {
				max_edge = current.value;
			}
			prim(current.vertex);
			return;
		}
		
	}
}


int main() {
	ios::sync_with_stdio(0); 
	cin.tie(0);
	int N, M, A, B, C;

	cin >> N >> M;



	for (int count = 0; count < M; count++) {
		cin >> A >> B >> C;
		MAP[A].push_back(vertex_value{ B, C });
		MAP[B].push_back(vertex_value{ A, C });

	}

	prim(1);
	cout << result - max_edge << endl;
}