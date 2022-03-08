#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#define MAX_SIZE 18

using namespace std;

int power_of_two[MAX_SIZE];
// 2^17 == 131072

vector<int> answer;

string delete_zero(const string& str) {
    string result = "";

    for (int index = 0; index < str.size(); index++) {
        if (str[index] == '1') {
            result += '1';
        }
        else {
            answer[1]++;
        }
    }

    return result;
}

string convert(const string& str) {
    int result = 0;

    // convert to int
    for (int index = 0; index < str.size(); index++) {
        if (str[index] == '1') {
            result++;
        }
    }

    // convert to string
    string result_str = "";
    bool ok = false;
    for (int index = 17; index >= 0; index--) {
        if (result >= power_of_two[index]) {
            ok = true;
            result_str += '1';
            result -= power_of_two[index];
        }
        else if (ok) {
            result_str += '0';
        }
    }

    return result_str;
}

vector<int> solution(string s) {
    // initialize
    for (int index = 0; index < MAX_SIZE; index++) {
        power_of_two[index] = pow(2, index);
    }
    answer.clear();

    answer.push_back(0);
    answer.push_back(0);

    string current_str = s;

    while (true) {
        // end condition
        if (current_str == "1") {
            break;
        }
        answer[0]++;
        current_str = convert(delete_zero(current_str));

    }



    return answer;
}

int main() {
    vector<int> result = solution("1111111");

    for (int index = 0; index < result.size(); index++) {
        cout << result[index] << " " << endl;
    }
}