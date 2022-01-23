#include <iostream>	
#include <vector>
#include <string>

using namespace std;

class Stack {
private:
	int size;
	vector<int> stack;
public:
	Stack() : size(0) {

	}
	bool isEmpty() {
		return size == 0;
	}
	void push(int d) {
		stack.push_back(d);
		size++;
	}
	void pop() {
		if (isEmpty()) {
			cout << "-1" << endl;
		}
		else {
			cout << stack[size - 1] << endl;
			stack.pop_back();
			size--;
		}
	}
	void empty() {
		if (isEmpty()) {
			cout << "1" << endl;
		}
		else {
			cout << "0" << endl;
		}
	}
	void top() {
		if (isEmpty()) {
			cout << "-1" << endl;
		}
		else {
			cout << stack[size - 1] << endl;
		}
	}
	void Size() {
		cout << size << endl;
	}
};

int main() {
	Stack st;

	int N;
	cin >> N;

	string cmd;
	for (int count = 0; count < N; count++) {
		cin >> cmd;
		if (cmd == "push") {
			int d;
			cin >> d;
			st.push(d);
		}
		else if (cmd == "pop") {
			st.pop();
		}
		else if (cmd == "size") {
			st.Size();
		}
		else if (cmd == "empty") {
			st.empty();
		}
		else {
			st.top();
		}
	}
}