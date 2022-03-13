#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

bool isCorrect(string& str) {
    stack<char> st;

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == ')') {
            if (st.empty() || st.top() != '(') {
                return false;
            }
            st.pop();
        }
        else if (str[i] == '}') {
            if (st.empty() || st.top() != '{') {
                return false;
            }
            st.pop();
        }
        else if (str[i] == ']') {
            if (st.empty() || st.top() != '[') {
                return false;
            }
            st.pop();
        }
        else {
            st.push(str[i]);
        }
    }
    if (st.empty()) {
        return true;
    }
    else {
        return false;
    }
}

int solution(string s) {


    int answer = 0;

    for (int count = 0; count < s.size() - 1; count++) {
        if (isCorrect(s)) {
            answer++;
        }
        s = s.substr(1, s.size() - 1) + s[0];
    }
    
    return answer;
}

int main() {
    cout << solution("}]()[{") << endl;
}