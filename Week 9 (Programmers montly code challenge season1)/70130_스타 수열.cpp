#include <iostream>
#include <vector>
#include <queue>
#define MAX_SIZE 500001

using namespace std;

vector<int> arr[MAX_SIZE];
bool visited[MAX_SIZE];
int ans = 0;
int Size;
queue<int> exist;

void initialize() {
    for (int i = 0; i < Size; i++) {
        visited[i] = false;
    }
}

int make_sequence(int target, vector<int>& vec) {
    int result = 0;

    for (int i = 0; i < arr[target].size(); i++) {
        int current_index = arr[target][i];
        visited[current_index] = true;
        // case 1
        if (current_index >= 1 && !visited[current_index - 1] && vec[current_index - 1] != target) {
            result += 2;
            visited[current_index - 1] = true;
        }
        // case 2
        else if (current_index < Size - 1 && vec[current_index + 1] != target) {
            result += 2;
            visited[current_index + 1] = true;
        }
        
    }

    return result;
}

int solution(vector<int> a) {
    Size = a.size();

    // search
    for (int i = 0; i < Size; i++) {
        arr[a[i]].push_back(i);

        // exist number
        if (!visited[a[i]]) {
            exist.push(a[i]);
            visited[a[i]] = true;
        }
    }

    while (!exist.empty()) {
        initialize();

        int result = make_sequence(exist.front(), a);
        exist.pop();

        if (result > ans) {
            ans = result;
        }
    }
    
    return ans;
}

int main() {
    vector<int> temp = { 0,3,3,0,7,2,0,2,2,0 };

    cout << solution(temp) << endl;
}