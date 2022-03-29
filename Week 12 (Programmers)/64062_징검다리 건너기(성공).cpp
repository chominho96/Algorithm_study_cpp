#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#define INF 200000001

using namespace std;

int stone_size;
int K;

int check(int left, int right, vector<int>& vec) {
    if (left == right) {
        return left;
    }
    
    int mid = (left + right) / 2;

    for (int i = 0; i < stone_size; i++) {
        if (vec[i] <= mid) {
            int cnt = 1;
            i++;
            if (cnt >= K) {
                // impossible
                return check(left, mid, vec);
            }
            
            while (true) {
                
                if (i < stone_size && vec[i] <= mid) {
                    cnt++;

                    if (cnt >= K) {
                        // impossible
                        return check(left, mid, vec);
                    }
                    else {
                        i++;
                    }
                }
                else {
                    break;
                }
            }
        }
    }

    return check(mid + 1, right, vec);
}

int solution(vector<int> stones, int k) {
    stone_size = stones.size();
    K = k;

    if (stone_size < k) {
        return *max_element(stones.begin(), stones.end());
    }

    return check(1, INF, stones);
}

int main() {
    cout << solution({ 2, 4, 5, 3, 2, 1, 4, 2, 5, 1 }, 3);
}