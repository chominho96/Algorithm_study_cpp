#include <iostream>
#include <queue>
#include <vector>
#define MAX_SIZE 501

using namespace std;

struct index_value {
	int index;
	int value;
};

struct compare {
	bool operator()(const index_value& i_v_1, const index_value& i_v_2) {
		return i_v_1.value < i_v_2.value;
	}
};

int DP[MAX_SIZE]{ 0 };
bool victory[MAX_SIZE][MAX_SIZE];
int initial_sequence[MAX_SIZE];

void initialize(int size) {
	for (int i = 1; i <= size; i++) {
		for (int j = 1; j <= size; j++) {
			victory[i][j] = false;
		}
		DP[i] = 0;
		initial_sequence[i] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, n, t, m, a, b;

	cin >> T;

	for (int count = 0; count < T; count++) {
		cin >> n;
		for (int index = 1; index <= n; index++) {
			cin >> t;
			DP[t] = n - index;
			initial_sequence[index] = t;
		}

		// make victory
		for (int i = 1; i < n; i++) {
			for (int j = i + 1; j <= n; j++) {
				victory[initial_sequence[i]][initial_sequence[j]] = true;
			}
		}

		cin >> m;
		for (int i = 0; i < m; i++) {
			cin >> a >> b;
			if (victory[a][b]) {
				DP[a]--;
				DP[b]++;
				victory[b][a] = true;
				victory[a][b] = false;
			}
			else {
				DP[a]++;
				DP[b]--;
				victory[a][b] = true;
				victory[b][a] = false;
			}
			
		}

		priority_queue<index_value, vector<index_value>, compare> que;
		bool flag = true;
		bool isImpossible = false;

		for (int index = 1; index <= n; index++) {
			que.push(index_value{ index, DP[index] });
		}

		int current = n;
		vector<int> result(n + 1);

		for (int index = n; index >= 1; index--) {
			result[n - index + 1] = que.top().index;
			if (que.top().value == current) {
				cout << "IMPOSSIBLE" << endl;
				isImpossible = true;
				flag = false;
				break;
			}

			if (que.top().value < index - 1) {
				flag = false;
			}
			current = que.top().value;
			que.pop();
		}

		if (flag) {
			for (int index = 1; index <= n; index++) {
				cout << result[index] << " ";
			}
			cout << endl;
		}
		else if (!isImpossible) {
			cout << "?" << endl;
		}

		initialize(n);
	}

	
}
