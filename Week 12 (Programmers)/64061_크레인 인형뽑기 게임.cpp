#include <string>
#include <vector>
#include <stack>
#include <iostream>
#define MAX_SIZE 31

using namespace std;

int MAP[MAX_SIZE][MAX_SIZE];
int next_index[MAX_SIZE];

int solution(vector<vector<int>> board, vector<int> moves) {
    // duplicate MAP
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board.size(); j++) {
            MAP[i + 1][j + 1] = board[i][j];
            if (MAP[i + 1][j + 1] && next_index[j + 1] == 0) {
                next_index[j + 1] = i + 1;
            }
        }
    }

    stack<int> bascket;
    int answer = 0;

    for (int i = 0; i < moves.size(); i++) {
        if (next_index[moves[i]] != 0 && next_index[moves[i]] <= board.size()) {
            int current = MAP[next_index[moves[i]]][moves[i]];
            next_index[moves[i]]++;
            
            if (!bascket.empty() && bascket.top() == current) {
                answer += 2;
                bascket.pop();
            }
            else {
                bascket.push(current);
            }
        }
    }
    

    
    return answer;
}

int main() {
    cout << solution({ {0, 0, 0, 0, 0},{0, 0, 1, 0, 3},{0, 2, 5, 0, 1},{4, 2, 4, 4, 2},{3, 5, 1, 3, 1} }, { 1, 5, 3, 5, 1, 2, 1, 4 });
}