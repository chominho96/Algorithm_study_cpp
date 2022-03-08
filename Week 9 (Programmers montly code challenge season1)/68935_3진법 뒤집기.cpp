#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#define MAX_SIZE 17

using namespace std;

int power_of_three[MAX_SIZE];

int solution(int n) {
    // 1. initialize
    for (int index = 0; index < MAX_SIZE; index++) {
        power_of_three[index] = int(pow(3, index));
    }

    // 2. calculate
    int ternary[MAX_SIZE]{ 0 };
    int last_index = -1;
    // 3^16 == 43046721
    for (int index = MAX_SIZE - 1; index >= 0; index--) {
        while (n - power_of_three[index] >= 0) {
            if (last_index == -1) {
                last_index = index;
            }
            ternary[index]++;
            n -= power_of_three[index];
        }
    }

    // 3. opposite and calculate result
    int answer = 0;
    for (int index = last_index; index >= 0; index--) {
        answer += int(pow(3, last_index - index)) * ternary[index];
    }
    return answer;
}

int main() {
    int T;
    cin >> T;
    cout << solution(T) << endl;
}