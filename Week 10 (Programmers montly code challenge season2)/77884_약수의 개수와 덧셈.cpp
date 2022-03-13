#include <string>
#include <vector>
#define MAX_SIZE 1001

using namespace std;

bool even[MAX_SIZE];

void judge() {
    for (int i = 2; i < MAX_SIZE; i++) {
        even[1] = false;

        // judge logic
        int measure = 0;
        for (int j = i; j >= 1; j--) {
            if (i % j == 0) {
                measure++;
            }
        }
        if (measure % 2 == 0) {
            even[i] = true;
        }
    }
}

int solution(int left, int right) {
    judge();
    int answer = 0;

    for (int i = left; i <= right; i++) {
        if (even[i]) {
            answer += i;
        }
        else {
            answer -= i;
        }
    }

    return answer;
}