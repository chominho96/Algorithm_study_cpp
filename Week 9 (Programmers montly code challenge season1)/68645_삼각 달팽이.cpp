#include <string>
#include <vector>
#include <iostream>
#define MAX_SIZE 500501

using namespace std;

bool visited[MAX_SIZE];

vector<int> solution(int n) {
    int size = n * (n + 1) / 2;
    vector<int> answer;
    answer.resize(size);

    answer[0] = 1;
    visited[0] = true;

    int index = 0;
    int current = 2;

    int counter = 1;

    while (current <= size) {
        // step 1
        int unit = counter++;

        while (index + unit < size && !visited[index + unit]) {
            answer[index + unit] = current;
            visited[index + unit] = true;
            index += unit++;
            current++;
        }

        // step 2
        while (index + 1 < size && !visited[index + 1]) {
            answer[index + 1] = current;
            visited[index + 1] = true;
            index++;
            current++;
        }

        // step 3
        while (index - unit >= 0 && !visited[index - unit]) {
            answer[index - unit] = current;
            visited[index - unit] = true;
            index -= unit--;
            current++;
        }

    }


    return answer;
}

int main() {
    vector<int> result = solution(1000);

    for (int index = 0; index < result.size(); index++) {
        cout << result[index] << " ";
    }
}