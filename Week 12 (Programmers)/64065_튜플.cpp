#include <string>
#include <vector>
#include <iostream>
#define MAX_SIZE 100001

using namespace std;

bool visited[MAX_SIZE];
vector<int> sub[501];
int res_size = 0;

vector<int> solution(string s) {
    vector<int> answer;

    // 1. make sub
    for (int i = 1; i < s.size() - 1; i++) {
        if (s[i] == '{') {
            vector<int> vec;
            i++;

            int current = 0;
            while (true) {
                if (s[i] == '}') {
                    vec.push_back(current);
                    break;
                }
                if (s[i] == ',') {
                    vec.push_back(current);
                    current = 0;
                    i++;
                    continue;
                }
                
                current = current * 10 + s[i] - '0';
                i++;
            }

            if (vec.size() > res_size) {
                res_size = vec.size();
            }
            sub[vec.size()] = vec;
        }
    }

    // 2. make tuple
    for (int i = 1; i <= res_size; i++) {
        for (int j = 0; j < i; j++) {
            if (!visited[sub[i][j]]) {
                visited[sub[i][j]] = true;
                answer.push_back(sub[i][j]);
                break;
            }
        }
    }
    

    return answer;
}

int main() {
    vector<int> result = solution("{{2},{2,1},{2,1,3},{2,1,3,4}}");
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
}