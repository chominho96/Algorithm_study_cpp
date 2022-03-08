#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#define INF 1000000001

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

int prev(vector<int>& vec, int index) {
    for (int i = index - 1; i >= 0; i--) {
        if (vec[i] != INF) {
            return i;
        }
    }
    return -1;
}

int next(vector<int>& vec, int index) {
    for (int i = index + 1; i < vec.size(); i++) {
        if (vec[i] != INF) {
            return i;
        }
    }
    return -1;
}

int solution(vector<int> a) {
    int answer = 0;

    int left = 0;
    int right = a.size() - 1;

    priority_queue<index_value, vector<index_value>, compare> pq;

    for (int i = 0; i < a.size(); i++) {
        pq.push(index_value{ i, a[i] });
    }

    while (!pq.empty()) {
        index_value current = pq.top();
        pq.pop();

        if (current.index == left) {
            answer++;
            left = next(a, current.index);
        }
        else if (current.index == right) {
            answer++;
            right = prev(a, current.index);
        }
        else {
            a[current.index] = INF;
        }

    }
    return answer;
}


int main() {
    vector<int> vec = { -16, 27, 65, -2, 58, -92, -71, -68, -61, -33 };
    cout << solution(vec) << endl;
}