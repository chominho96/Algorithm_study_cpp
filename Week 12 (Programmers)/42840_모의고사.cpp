#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;

    int ans_1 = 0, ans_2 = 0, ans_3 = 0;
    int way_1[]{ 1, 2, 3, 4, 5 };
    // size 5
    int way_2[]{ 2, 1, 2, 3, 2, 4, 2, 5 };
    // size 8
    int way_3[]{ 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };
    // size 10

    // brute force
    for (int i = 0; i < answers.size(); i++) {
        // ans 1
        if (way_1[i % 5] == answers[i]) {
            ans_1++;
        }
        // ans 2
        if (way_2[i % 8] == answers[i]) {
            ans_2++;
        }
        // ans 3
        if (way_3[i % 10] == answers[i]) {
            ans_3++;
        }
    }
    if (ans_1 >= ans_2 && ans_1 >= ans_3) {
        answer.push_back(1);
        if (ans_1 == ans_2) {
            answer.push_back(2);
        }
        if (ans_1 == ans_3) {
            answer.push_back(3);
        }
    }
    else if (ans_2 >= ans_1 && ans_2 >= ans_3) {
        answer.push_back(2);
        if (ans_2 == ans_1) {
            answer.push_back(1);
        }
        if (ans_2 == ans_3) {
            answer.push_back(3);
        }
    }
    else {
        answer.push_back(3);
        if (ans_3 == ans_1) {
            answer.push_back(1);
        }
        if (ans_3 == ans_2) {
            answer.push_back(2);
        }
    }
    sort(answer.begin(), answer.end());

    
    return answer;
}

int main() {
    vector<int> ans = solution({ 1, 2, 3, 4, 5 });
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}