#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

string move_110(string str) {
    int num_110 = 0;

    stack<char> st;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '0' && st.size() >= 2) {
            int first = st.top();
            st.pop();
            int second = st.top();
            st.pop();

            if (first == '1' && second == '1') {
                num_110++;
            }
            else {
                st.push(second);
                st.push(first);
                st.push('0');
            }
        }
        else {
            st.push(str[i]);
        }
    }

    //cout << num_110 << endl;

    string result = "";
    while (!st.empty()) {
        result = st.top() + result;
        st.pop();
    }

    //cout << result << endl;

    // add 110
    int i;
    for (i = result.size() - 1; i >= 0; i--) {
        if (result[i] == '0') {
            break;
        }
    }

    string temp = "";
    for (int j = 0; j < num_110; j++) {
        temp += "110";
    }

    result = result.substr(0, i + 1) + temp + result.substr(i + 1);

    return result;

}

vector<string> solution(vector<string> s) {
    vector<string> answer;

    for (int i = 0; i < s.size(); i++) {
        answer.push_back(move_110(s[i]));
    }


    return answer;
}

int main() {
    /*string temp = "12345";
    cout << temp.substr(5, 4) << endl;*/
    cout << move_110("1100111011101001") << endl;
}





//int index = 0;

//// disunite 110
//while (true) {

//    //if (index >= str.size() - 2) {
//    //    // end condition
//    //    break;
//    //}
//    string current = str.substr(index, 3);
//    
//    if (current.size() < 3) {
//        // end condition
//        break;
//    }

//    if (current == "110") {
//        num_110++;

//        str = str.substr(0, index) + str.substr(index + 3);
//    }
//    else if (current == "111") {
//        int i = index;
//        while (i < str.size() && str[i] == '1') {
//            i++;
//        }
//        if (i == str.size()) {
//            // end condtiton
//            break;
//        }
//        else {
//            num_110++;
//            string result = "";

//            str = str.substr(0, i - 2) + str.substr(i + 1);

//        }


//    }
//    else {
//        index++;
//    }
//}

//// add 110
//int i;
//for (i = str.size() - 1; i >= 0; i--) {
//    if (str[i] == '0') {
//        break;
//    }
//}

//string temp = "";
//for (int j = 0; j < num_110; j++) {
//    temp += "110";
//}

//str = str.substr(0, i + 1) + temp + str.substr(i + 1);
//
//return str;