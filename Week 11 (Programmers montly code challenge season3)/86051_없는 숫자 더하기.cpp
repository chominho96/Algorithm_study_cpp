#include <string>
#include <vector>

using namespace std;

bool visited[10];

int solution(vector<int> numbers) {
    int result = 0;
    int answer = 45;

    for (int i = 0; i < numbers.size(); i++) {
        if (result == 10) {
            break;
        }
        if (result != 10 && !visited[numbers[i]]) {
            answer -= numbers[i];
            visited[numbers[i]] = true;
            result++;
        }
    }

    return answer;
}