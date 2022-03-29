#include <string>
#include <vector>

using namespace std;


vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    for (int i = 1; i <= yellow; i++) {
        if (yellow % i == 0) {
            int width = yellow / i;
            int height = i;
            if (width * 2 + height * 2 + 4 == brown) {
                answer.push_back(width + 2);
                answer.push_back(height + 2);
                return answer;
            }
        }
    }
    
    return answer;
}