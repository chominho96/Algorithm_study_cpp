#include <string>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

bool possible[8][8];
// possible[N][M] means banned_id[N] can make user_id[M]
int pow_of_10[8];
int ban_size, user_size;

bool visited[8];
int answer = 0;

set<int> duplicate;

void combination(int idx, int prev) {
    if (idx >= ban_size) {
        if (duplicate.find(prev) == duplicate.end()) {
            duplicate.insert(prev);
            answer++;
        }
        return;
    }
    
    for (int i = 0; i < user_size; i++) {
        if (!visited[i] && possible[idx][i]) {
            // before
            visited[i] = true;
            combination(idx + 1, prev + pow_of_10[i]);

            // after
            visited[i] = false;

            
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    // initialize
    user_size = user_id.size();
    ban_size = banned_id.size();
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            possible[i][j] = true;
        }
        pow_of_10[i] = pow(10, i);
    }
    // 1. make possible case
    for (int i = 0; i < ban_size; i++) {
        string& current_ban = banned_id[i];
        for (int j = 0; j < user_size; j++) {
            if (current_ban.size() != user_id[j].size()) {
                possible[i][j] = false;
            }
        }
        for (int j = 0; j < current_ban.size(); j++) {
            if (current_ban[j] != '*') {
                for (int k = 0; k < user_size; k++) {
                    string& current_user = user_id[k];
                    if (possible[i][k] && current_ban[j] != current_user[j]) {
                        possible[i][k] = false;
                    }
                }
            }
        }   
    }

    // 2. calculate combination
    for (int i = 0; i < user_size; i++) {
        if (possible[0][i]) {
            // before
            visited[i] = true;
            combination(1, pow_of_10[i]);

            // after
            visited[i] = false;
        }
    }

    return answer;
}

int main() {
    solution({ "frodo", "fradi", "crodo", "abc123", "frodoc" }, { "*rodo", "*rodo", "******" });
}