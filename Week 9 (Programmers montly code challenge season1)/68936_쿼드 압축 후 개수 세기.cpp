#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#define MAX_SIZE 1025

using namespace std;


vector<int> answer;


void find(int row, int col, int level, const vector<vector<int>>& arr) {
    if (level == 1) {
        // end condition
        if (arr[row][col] == 0) {
            answer[0]++;
        }
        else {
            answer[1]++;
        }
        return;
    }

    int current = arr[row][col];
    bool success = true;
    for (int i = row; i < row + level; i++) {
        for (int j = col; j < col + level; j++) {
            if (arr[i][j] != current) {
                success = false;
                break;
            }
        }
        if (!success) {
            break;
        }
    }

    if (success) {
        answer[current]++;
    }
    else {
        int next_level = level / 2;
        find(row, col, next_level, arr);
        find(row + next_level, col, next_level, arr);
        find(row, col + next_level, next_level , arr);
        find(row + next_level, col + next_level, next_level , arr);
    }
}




vector<int> solution(vector<vector<int>> arr) {
    // initialize
    answer.clear();
    answer.push_back(0);
    answer.push_back(0);
    

    find(0, 0, arr.size(), arr);

    return answer;
}

int main() {
    vector<vector<int>> arr;
    arr.push_back(vector<int>{1, 1, 0, 0});
    arr.push_back(vector<int>{1, 0, 0, 0});
    arr.push_back(vector<int>{1, 0, 0, 1});
    arr.push_back(vector<int>{1, 1, 1, 1});

    solution(arr);

    for (int index = 0; index < 2; index++) {
        cout << answer[index] << " ";
    }
}