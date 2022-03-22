#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#define MAX_SIZE 501

using namespace std;

char MAP[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE][4];
bool cycleRoute[MAX_SIZE][MAX_SIZE][4];
int right_value, c;
int cycle_length = 0;

int origin_row;
int origin_col;
int origin_dir;

int dx[]{ 1, 0, -1, 0 };
int dy[]{ 0, -1, 0, 1 };
    // dir : 0 = top to bottom
    // dir : 1 = right to left
    // dir : 2 = bottom to top
    // dir : 3 = left to right

queue<int> row_que;
queue<int> col_que;
queue<int> dir_que;


void initialize_success() {

    while (!row_que.empty()) {
        visited[row_que.front()][col_que.front()][dir_que.front()] = false;
        cycleRoute[row_que.front()][col_que.front()][dir_que.front()] = true;

        row_que.pop();
        col_que.pop();
        dir_que.pop();
    }
    cycle_length = 0;
}
void initialize_fail() {
    while (!row_que.empty()) {
        visited[row_que.front()][col_que.front()][dir_que.front()] = false;

        row_que.pop();
        col_que.pop();
        dir_que.pop();
    }
    cycle_length = 0;
}


bool isRoute(const int& row, const int& col) {
    return row >= 1 && row <= right_value && col >= 1 && col <= c;
}

bool isCycle(const int& row, const int& col, const int& dir, bool isFirst) {
    if (isFirst) {
        origin_row = row;
        origin_col = col;
        origin_dir = dir;
    }
    if (cycleRoute[row][col][dir]) {
        // already checked cycle
        return false;
    }

    row_que.push(row);
    col_que.push(col);
    dir_que.push(dir);

    // true condition
    if (!isFirst && row == origin_row && col == origin_col && dir == origin_dir) {
        return true;
    }

    if (visited[row][col][dir]) {
        return false;
    }

    cycle_length++;

    visited[row][col][dir] = true;
    
    int next_dir;
    if (MAP[row][col] == 'S') {
        next_dir = dir;
    }
    else if (MAP[row][col] == 'L') {

        switch (dir)
        {
        case 0:
            next_dir = 3;
            break;
        case 1:
            next_dir = 0;
            break;
        case 2:
            next_dir = 1;
            break;
        default:
            next_dir = 2;
            break;
        }
    }
    else {
        switch (dir)
        {
        case 0:
            next_dir = 1;
            break;
        case 1:
            next_dir = 2;
            break;
        case 2:
            next_dir = 3;
            break;
        default:
            next_dir = 0;
            break;
        }
    }

    int next_row = row + dx[next_dir];
    int next_col = col + dy[next_dir];

    if (isRoute(next_row, next_col)) {
        return isCycle(next_row, next_col, next_dir, false);
    }
    else {
        if (next_row == 0) {
            return isCycle(right_value, next_col, next_dir, false);
        }
        else if (next_row == right_value + 1) {
            return isCycle(1, next_col, next_dir, false);
        }
        else if (next_col == 0) {
            return isCycle(next_row, c, next_dir, false);
        }
        else {
            return isCycle(next_row, 1, next_dir, false);
        }
    }
}

vector<int> solution(vector<string> grid) {
    vector<int> answer;


    // make map
    right_value = grid.size();
    c = grid[0].size();
    
    for (int i = 1; i <= right_value; i++) {
        for (int j = 1; j <= c; j++) {
            MAP[i][j] = grid[i - 1][j - 1];
        }
    }

    // find
    for (int i = 1; i <= right_value; i++) {
        for (int j = 1; j <= c; j++) {
            for (int k = 0; k < 4; k++) {
                if (isCycle(i, j, k, true)) {
                    answer.push_back(cycle_length);
                    initialize_success();
                }
                else {
                    initialize_fail();
                }
            }
        }
    }

    sort(answer.begin(), answer.end());

    return answer;
}

int main() {
    //vector<string> grid = { "SL", "LR" };
    vector<string> grid = { "R" };
    vector<int> result = solution(grid);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << ' ';
    }
}