//#include <iostream>
//#include <queue>
//#define MAX_WEIGHT 100001
//
//using namespace std;
//
//int item[MAX_WEIGHT]{ 0 };
//int DP[MAX_WEIGHT]{ 0 };
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	int N, K, W, V;
//
//	cin >> N >> K;
//
//	for (int count = 0; count < N; count++) {
//		cin >> W >> V;
//		if (item[W] < V) {
//			item[W] = V;
//		}
//	}
//	int result = 0;
//	for (int index = 1; index <= K; index++) {
//		bool flag = true;
//		if (item[index] > DP[index]) {
//			DP[index] = item[index];
//		}
//		else {
//			flag = false;
//		}
//		
//		
//		if (DP[index] < DP[index - 1]) {
//			DP[index] = DP[index - 1];
//			flag = false;
//		}
//		if (!flag) {
//			if (DP[index] != 0) {
//				if (index * 2 <= K && DP[index * 2] < DP[index] + item[index]) {
//					DP[index * 2] = DP[index] + item[index];
//				}
//			}
//		
//		}
//		
//		for (int i = index + 1; index + i <= K; i++) {
//			if (DP[index + i] < DP[index] + item[i]) {
//				DP[index + i] = DP[index] + item[i];
//			}
//		}
//
//		if (DP[index] > result) {
//			result = DP[index];
//		}
//		
//	}
//
//	cout << result << endl;
//}