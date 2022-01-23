#include <iostream>
#include <stack>

using namespace std;



int main() {
	int num_of_computer;
	int test_num;

	cin >> num_of_computer >> test_num;


	char arr[101][101]{ 0 };

	bool* isVisited = new bool[num_of_computer + 1];		// not use index 0;
	for (int index = 0; index < num_of_computer + 1; index++) {
		isVisited[index] = false;
	}

	int x, y;

	for (int count = 0; count < test_num; count++) {
		cin >> x >> y;
		arr[x][y] = 1;
		arr[y][x] = 1;
	}

	int result = 0;
	stack<int> next;
	for (int index = 1; index <= num_of_computer; index++) {
		if (arr[1][index] == 1) {
			next.push(index);
			isVisited[index] = true;
			arr[1][index] = 0;
			arr[index][1] = 0;
			result++;

		}
	}

	while (!next.empty()) {
		
		int start = next.top();
		next.pop();


		for (int index = 1; index <= num_of_computer; index++) {
			if (arr[start][index] == 1) {
				next.push(index);
				arr[start][index] = 0;
				arr[index][start] = 0;
				if (isVisited[index] == false) {
					result++;
					isVisited[index] = true;
				}
				
			}
		}
	}

	cout << result << endl;


}