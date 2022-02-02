#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct meeting {
	int start;
	int end;
};

struct compare {
	bool operator()(meeting& m_1, meeting& m_2) {
		if (m_1.end == m_2.end) {
			return m_1.start > m_2.start;
		}
		else {
			return m_1.end > m_2.end;
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	priority_queue<meeting, vector<meeting>, compare> meeting_que;
	int result = 0;
	int current_end_time = 0;

	int N, start, end;

	cin >> N;
	for (int count = 0; count < N; count++) {
		cin >> start >> end;
		meeting_que.push(meeting{ start, end });
	}

	while (!meeting_que.empty()) {
		meeting current = meeting_que.top();
		meeting_que.pop();
		
		if (current.start >= current_end_time) {
			result++;
			current_end_time = current.end;
		}
	}

	cout << result << endl;
}