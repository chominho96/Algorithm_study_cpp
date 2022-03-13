#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <iostream>
#define MAX_SIZE 300000

using namespace std;

vector<int> MAP[MAX_SIZE];
vector<int> vertex;
vector<long long> weight;
bool visited[MAX_SIZE];
int N;

void make_map(vector<vector<int>>& edges) {
    for (int i = 0; i < edges.size(); i++) {
        MAP[edges[i][0]].push_back(edges[i][1]);
        MAP[edges[i][1]].push_back(edges[i][0]);
        
        // means num of valid edges
        vertex[edges[i][0]]++;
        vertex[edges[i][1]]++;
    }
}

long long bottom_up(vector<long long>& weight) {
    long long result = 0;
    int root = -1;

    queue<int> next_que;
    
    // calculate root
    // any leaf node can be root
    for (int i = 0; i < N; i++) {
        if (MAP[i].size() == 1) {
            root = i;
            break;
        }
    }

    // first search
    for (int i = 0; i < N; i++) {
        // if leaf node
        if (MAP[i].size() == 1 && i != root) {
            visited[i] = true;
            next_que.push(i);

        }
    }

    // find until there is no leaf node
    while (!next_que.empty()) {
        int current = next_que.front();
        next_que.pop();

        // find parent
        int next;
        for (int i = 0; i < MAP[current].size(); i++) {
            next = MAP[current][i];
            if (!visited[next]) {
                break;
            }
        }

        vertex[next]--;

        if (vertex[next] == 1 && next != root) {
            visited[next] = true;
            next_que.push(next);
        }

        // continue condition
        if (weight[current] == 0) {
            continue;
        }


        result += abs(weight[current]);
        weight[next] += weight[current];

        // end condition
        if (next == root && vertex[root] == 0) {
            if (weight[root] != 0) {
                return -1;
            }
            else {
                return result;
            }
        }

    }

    if (vertex[root] == 0 && weight[root] == 0) {
        return result;
    }
    else {
        return -1;
    }
    
    
}

long long solution(vector<int> a, vector<vector<int>> edges) {
    N = a.size();
    vertex.resize(N);

    weight.reserve(N);
    // copy a to weight
    for (int i = 0; i < N; i++) {
        weight.push_back(a[i]);
    }
    
    
    make_map(edges);
    return bottom_up(weight);

}

int main() {
    /*vector<int> a = { -5, 0, 2, 1, 2 };
    vector<vector<int>> edges = { {0, 1}, {3, 4},{2, 3}, {0, 3} };*/
    /*vector<int> a = { 0, 1, 0 };
    vector<vector<int>> edges = { {0, 1}, {1, 2}};*/
    vector<int> a = { -2, 8, -5, -5, -3, 0, 5, 2 };
    vector<vector<int>> edges = { {0, 1} ,{0, 2},{1, 3},{1, 4},{1, 5},{2, 6},{2, 7} };

    cout << solution(a, edges) << endl;
}