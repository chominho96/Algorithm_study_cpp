#include <iostream>	
#include <queue>

using namespace std;

struct data_pos {
	int pos;
	int importance;
};

int main() {
	int T;
	// test num
	cin >> T;

	int N, M;

	for (int count = 0; count < T; count++) {
		cin >> N >> M;
		priority_queue<int> p_que;
		queue<data_pos> que;

		int imp;
		int index = 1;
		for (int inner_count = 0; inner_count < N; inner_count++) {
			cin >> imp;
			p_que.push(imp);
			que.push(data_pos{inner_count, imp});
		}
		
		while (!que.empty()) {
			data_pos data = que.front();
			que.pop();
			
			if (data.importance == p_que.top()) {
				p_que.pop();

				if (data.pos == M) {
					cout << index << endl;
					break;
				}

				index++;
			}
			else {
				que.push(data);
			}
			
		}
		
		
	}
}
