#include <iostream>
#include <queue>
#define MAX_SIZE 101

using namespace std;

int DP[MAX_SIZE][MAX_SIZE]{ 0 };
long long result[MAX_SIZE][MAX_SIZE]{ 0 };

bool is_not_basic[MAX_SIZE];
bool is_made[MAX_SIZE];



void make_map(int target, int size) {
	if (is_made[target]) {
		return;
	}
	
	if (is_not_basic[target]) {

		for (int index = 1; index <= size; index++) {
			if (DP[target][index] != 0) {
				// if it needs index
				if (!is_not_basic[index]) {
					result[target][index] += DP[target][index];
				}
				else if (is_made[index]) {
					for (int i = 1; i <= size; i++) {

						result[target][i] += (result[index][i] * DP[target][index]);
					}
				}
				else {
					make_map(index, size);
					is_made[index] = true;

					for (int i = 1; i <= size; i++) {

						result[target][i] += (result[index][i] * DP[target][index]);
					}
					
				}

			}
		}
		is_made[target] = true;
	}
}



int main() {
	int N, M, start, end, num;
	cin >> N;
	cin >> M;

	for (int count = 0; count < M; count++) {
		cin >> start >> end >> num;
		is_not_basic[start] = true;
		DP[start][end] = num;
	}

	for (int index = 1; index <= N; index++) {
		make_map(index, N);
	}

	for (int index = 1; index < N; index++) {
		if (!is_not_basic[index]) {
			cout << index << " " << result[N][index] << "\n";
		}
	}


}