#include <iostream>
#include <vector>
constexpr auto MAX_SIZE = 501;

using namespace std;

vector<int> MAP[MAX_SIZE];
bool visited[MAX_SIZE];
// not use index 0

int tree_num = 0;
bool isCycle = false;

bool DFS(int current, int prev) {
	if (visited[current]) {
		return false;
		// it means it is already cheked node
	}

	visited[current] = true;
	for (int index = 0; index < MAP[current].size(); index++) {
		int next = MAP[current][index];
		if (next != prev && visited[next]) {
			// if it has cycle
			isCycle = true;
		}
		else if (next != prev) {
			DFS(next, current);
		}
	}
	return true;
}

int main() {
	for (int index = 0; index < MAX_SIZE; index++) {
		visited[index] = false;
	}

	int n, m;
	int current_case = 1;
	while (true) {
		cin >> n >> m;
		if (n == 0 && m == 0) {
			break;
		}
		else {
			int begin, end;
			for (int count = 0; count < m; count++) {
				cin >> begin >> end;
				MAP[begin].push_back(end);
				MAP[end].push_back(begin);
			}

			// main code

			for (int count = 1; count <= n; count++) {
				if (DFS(count, -1)) {
					if (!isCycle) {
						tree_num++;
					}
					else {
						isCycle = false;
					}
				}
			}

			// print
			cout << "Case " << current_case << ": ";

			if (tree_num == 0) {
				cout << "No trees." << endl;
			}
			else if (tree_num == 1) {
				cout << "There is one tree." << endl;
			}
			else {
				cout << "A forest of " << tree_num << " trees." << endl;
			}
			current_case++;


			// initiaiize
			for (int index = 1; index <= n; index++) {
				visited[index] = false;
				if (!MAP[index].empty()) {
					MAP[index].clear();
				}
			}
			tree_num = 0;

		}
	}
}