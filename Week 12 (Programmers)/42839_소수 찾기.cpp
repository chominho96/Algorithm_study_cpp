#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> number_vec;
bool visited[8];
int ans = 0;
bool maked[10000000];

void combination(int idx, int prev) {
    int current = prev * 10 + number_vec[idx];

    // check whether it is prime nubmer
    if (!maked[current]) {
        if (current == 2 || current == 3) {
            maked[current] = true;
            ans++;
        }
        else if (current != 1 && current != 0) {
            bool success = true;
            for (int i = 2; i <= current / 2; i++) {
                if (current % i == 0) {
                    success = false;
                    break;
                }
            }
            if (success) {
                maked[current] = true;
                ans++;
            }
        }
    }
    

    // go next
    for (int i = 0; i < number_vec.size(); i++) {
        if (!visited[i]) {
            // before
            visited[i] = true;
            combination(i, current);
            
            // after
            visited[i] = false;
        }
    }
   
}

int solution(string numbers) {
    for (int i = 0; i < numbers.size(); i++) {
        number_vec.push_back(numbers[i] - '0');
    }

    for (int i = 0; i < number_vec.size(); i++) {
        visited[i] = true;
        combination(i, 0);
        visited[i] = false;
    }

    return ans;

}

int main() {
    cout << solution("011") << endl;
}