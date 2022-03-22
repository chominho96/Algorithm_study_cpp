#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

long long right_value = 4 * 100000000000000;
long long left_value = 0;

int gold;
int silver;

long long binary_search(const long long& l, const long long& r, vector<int>& g, vector<int>& s, vector<int>& w, vector<int>& t) {
    // end condition
    if (l == r) {
        return l;
    }

    long long mid = (l + r) / 2;


    // judge whether can move gold and silver

    long long gold_result = 0;
    long long silver_result = 0;
    long long sum_result = 0;

    long long current_jewerly = 0;

    for (int i = 0; i < g.size(); i++) {

        if (mid >= t[i]) {
            current_jewerly = w[i];
        }
        else {
            continue;
        }
        current_jewerly += (long long)((mid - t[i]) / (2 * t[i])) * w[i];

        current_jewerly > g[i] ? gold_result += g[i] : gold_result += current_jewerly;
        current_jewerly > s[i] ? silver_result += s[i] : silver_result += current_jewerly;
        current_jewerly > g[i] + s[i] ? sum_result += (g[i] + s[i]) : sum_result += current_jewerly;
        

        
        if (gold_result >= gold && silver_result >= silver && sum_result >= gold + silver) {
            return binary_search(l, mid, g, s, w, t);
        }
  
    }
    return binary_search(mid + 1, r, g, s, w, t);
}


long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {
    gold = a;
    silver = b;
    
    return binary_search(left_value, right_value, g, s, w, t);

}

int main() {
    cout << solution(10, 10, { 100 }, { 100 }, { 7 }, { 10 }) << endl;
}