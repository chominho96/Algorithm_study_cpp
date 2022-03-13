#include <string>
#include <vector>
#include <bitset>
#include <iostream>
#include <cmath>
#define MAX_SIZE 51

using namespace std;

long long power_of_two[MAX_SIZE];

void initialize() {
    for (int i = 0; i < MAX_SIZE; i++) {
        power_of_two[i] = pow(2, i);
    }
}

long long binary_to_dec(string& str) {
    long long result = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '1') {
            result += power_of_two[str.size() - i - 1];
        }
    }
    return result;
}

vector<long long> solution(vector<long long> numbers) {
    initialize();
    vector<long long> answer;

    for (int i = 0; i < numbers.size(); i++) {
        // EXCEPTION : 0
        if (numbers[i] == 0) {
            answer.push_back(1);
            continue;
        }
        bitset<100> bs(numbers[i]);
        string s = bs.to_string();
        s = s.substr(s.find('1'));

        
        if (s[s.size() - 1] == '0') {
            s[s.size() - 1] = '1';
            answer.push_back(binary_to_dec(s));
        }

        else {
            s = '0' + s;
            for (int i = s.size() - 2; i >= 0; i--) {
                if (s[i] == '0') {
                    s[i] = '1';
                    s[i + 1] = '0';
                    break;
                }
            }
            s = s.substr(s.find('1'));
            answer.push_back(binary_to_dec(s));
        }
    }
    

    
    return answer;
}

int main() {
    vector<long long> result = solution({ 0, 7, 1 });
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    
}