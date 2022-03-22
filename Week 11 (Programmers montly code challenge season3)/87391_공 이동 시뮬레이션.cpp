#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

long long dx[]{ 0, 0, -1, 1 };
long long dy[]{ -1, 1, 0, 0 };
// 0 : (0, -1)
// 1 : (0, 1)
// 2 : (-1, 0)
// 3 : (1, 0)

vector<vector<int>> query;
int row_size;
int col_size;

long long find_range(int row, int col) {
    long long top = row;
    long long bottom = row;
    long long left = col;
    long long right = col;


    for (int i = query.size() - 1; i >= 0; i--) {
        switch (query[i][0])
        {
        case 0:
            if (left != 0) {
                // EXCEPTION
                if (left + query[i][1] >= col_size && right + query[i][1] >= col_size) {
                    return 0;
                }
                left + query[i][1] >= col_size ? left = col_size - 1 : left += query[i][1];
            }
            right + query[i][1] >= col_size ? right = col_size - 1 : right += query[i][1];
            break;
        case 1:
            if (right != col_size - 1) {
                // EXCEPTION
                if (left - query[i][1] < 0 && right - query[i][1] < 0) {
                    return 0;
                }
                right - query[i][1] < 0 ? right = 0 : right -= query[i][1];
            }
            left - query[i][1] < 0 ? left = 0 : left -= query[i][1];
            break;
        case 2:
            if (top != 0) {
                // EXCEPTION
                if (top + query[i][1] >= row_size && bottom + query[i][1] >= row_size) {
                    return 0;
                }
                top + query[i][1] >= row_size ? top = row_size - 1 : top += query[i][1];
            }
            bottom + query[i][1] >= row_size ? bottom = row_size - 1 : bottom += query[i][1];
            break;
        case 3:
            if (bottom != row_size - 1) {
                // EXCEPTION
                if (top - query[i][1] < 0 && bottom - query[i][1] < 0) {
                    return 0;
                }
                bottom - query[i][1] < 0 ? bottom = 0 : bottom -= query[i][1];
            }
            top - query[i][1] < 0 ? top = 0 : top -= query[i][1];
            break;
        }      
    }
    if (bottom - top < 0 || right - left < 0) {
        return 0;
    }
    return (bottom - top + 1) * (right - left + 1);
}





long long solution(int n, int m, int x, int y, vector<vector<int>> queries) {
    // copy queries to query
    query.reserve(queries.size());

    for (int i = 0; i < queries.size(); i++) {
        query.push_back(queries[i]);
    }

    // copy grid size and target
    row_size = n;
    col_size = m;

    return find_range(x, y);

}

int main() {
    cout << solution(1000, 1000, 1, 1, { {0, 100001}, {2, 100001} });
}

//void find(int row, int col, int idx) {
//
//    row_que.push(row);
//    col_que.push(col);
//    idx_que.push(idx);
//
//
//    while (!row_que.empty()) {
//        long long current_row = row_que.front();
//        long long current_col = col_que.front();
//        long long current_idx = idx_que.front();
//
//        row_que.pop();
//        col_que.pop();
//        idx_que.pop();
//
//
//        // end condition
//        if (current_idx == -1) {
//            /*if (!isIn(current_row, current_col)) {
//                answer++;
//                result.push_back({ current_row, current_col });
//            }*/
//            answer++;
//            continue;
//        }
//
//        
//
//        // calculate
//
//        if (query[current_idx][0] == 2 && current_row == 0) {
//            // 올라오는 경우인데 현재 맨 위
//            for (int i = 0; i <= query[current_idx][1]; i++) {
//                if (current_row + i < row_size) {
//                    row_que.push(current_row + i);
//                    col_que.push(current_col);
//                    idx_que.push(current_idx - 1);
//                }
//                else {
//                    break;
//                }
//            }
//            
//        }
//        else if (query[current_idx][0] == 3 && current_row == row_size - 1) {
//            // 내려오는 경우인데 현재 맨 밑
//            for (int i = 0; i <= query[current_idx][1]; i++) {
//                if (current_row - i >= 0) {
//                    row_que.push(current_row - i);
//                    col_que.push(current_col);
//                    idx_que.push(current_idx - 1);
//                }
//                else {
//                    break;
//                }
//            }
//        }
//        else if (query[current_idx][0] == 0 && current_col == 0) {
//            // 왼쪽으로 가는데 현재 맨 왼쪽
//            for (int i = 0; i <= query[current_idx][1]; i++) {
//                if (current_col + i < col_size) {
//                    row_que.push(current_row);
//                    col_que.push(current_col + i);
//                    idx_que.push(current_idx - 1);
//                }
//                else {
//                    break;
//                }
//            }
//        }
//        else if (query[current_idx][0] == 1 && current_col == col_size - 1) {
//            // 오른쪽으로 가는데 현재 맨 오른쪽
//            for (int i = 0; i <= query[current_idx][1]; i++) {
//                if (current_col - i >= 0) {
//                    row_que.push(current_row);
//                    col_que.push(current_col - i);
//                    idx_que.push(current_idx - 1);
//                }
//                else {
//                    break;
//                }
//            }
//        }
//        else {
//
//            // 그게 아니면 무조건 되야함
//            long long next_row = current_row - dx[query[current_idx][0]] * query[current_idx][1];
//            long long next_col = current_col - dy[query[current_idx][0]] * query[current_idx][1];
//            if (next_row >= 0 && next_row < row_size && next_col >= 0 && next_col < col_size) {
//                row_que.push(next_row);
//                col_que.push(next_col);
//                idx_que.push(current_idx - 1);
//            }
//        }
//        
//    }
//
//}