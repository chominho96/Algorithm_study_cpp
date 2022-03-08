#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool visited[201];
// 0 <= sum <= 200

vector<int> solution(vector<int> numbers) {
    vector<int> answer;

    for (int i = 0; i < numbers.size(); i++) {
        for (int j = i + 1; j < numbers.size(); j++) {
            if (!visited[numbers[i] + numbers[j]]) {
                answer.push_back(numbers[i] + numbers[j]);
                visited[numbers[i] + numbers[j]] = true;
            }
        }
    }

    sort(answer.begin(), answer.end());



    return answer;
}