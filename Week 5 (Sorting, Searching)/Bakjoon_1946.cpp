#include <iostream>
#include <queue>

using namespace std;

struct score {
	int document;
	int meeting;
};

struct document_cmp {
	bool operator()(score& s_1, score& s_2) {
		return s_1.document > s_2.document;
	}
};


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int T, N, doc, meet;

	cin >> T;

	for (int count = 0; count < T; count++) {
		priority_queue<score, vector<score>, document_cmp> doc_que;

		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> doc >> meet;
			doc_que.push(score{ doc, meet });
		}

		score doc_first = doc_que.top();
		doc_que.pop();

		int result = 1;
		int possible_meeting = doc_first.meeting;

		while (!doc_que.empty()) {
			score current = doc_que.top();
			doc_que.pop();

			if (current.meeting < possible_meeting) {
				result++;
				possible_meeting = current.meeting;
			}
		}
		cout << result << endl;



	}
}