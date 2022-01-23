#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class node {
	int data;
	node* left;
	node* right;
public:
	node(int d) : data(d), left(NULL), right(NULL) {

	}
	int getData() {
		return data;
	}
	void setData(int d) {
		data = d;
	}
	node* getLeft() {
		return left;
	}
	void setLeft(node* n) {
		left = n;
	}
	node* getRight() {
		return right;
	}
	void setRight(node* n) {
		right = n;
	}
};

class tree {
	int size;
	node* head;
public:
	tree() : size(0), head(NULL) {

	}
	bool isEmpty() {
		return size == 0;
	}

	node* getHead() {
		return head;
	}
	void setHead(int n) {
		if (isEmpty()) {
			head = new node(n);
			size++;
		}
		else {
			head->setData(n);
		}
	}

	void postorder(node* start) {
		if (start == NULL) {
			return;
		}
		else {
			postorder(start->getLeft());
			postorder(start->getRight());
			cout << start->getData() << " ";
		}
	}
	void postorder() {
		if (isEmpty()) {
			return;
		}
		else {
			postorder(head);
			cout << endl;
		}
	}
};


void makeTree(node* start, deque<int> pre_left, deque<int> in_left) {
	// end condition
	if (pre_left.size() <= 1) {
		return;
	}

	int root = pre_left.front();

	// step 1 : spiit deque
	deque<int> pre_right;
	deque<int> in_right;

	while (in_left.back() != root) {
		pre_right.push_front(pre_left.back());
		pre_left.pop_back();
		in_right.push_front(in_left.back());
		in_left.pop_back();
	}

	pre_left.pop_front();
	in_left.pop_back();
	
	// set Left
	if (pre_left.size() >= 1) {
		start->setLeft(new node(pre_left.front()));

		makeTree(start->getLeft(), pre_left, in_left);
	}
	if (pre_right.size() >= 1) {
		start->setRight(new node(pre_right.front()));
		makeTree(start->getRight(), pre_right, in_right);
	}
}

int main() {
	int T, n;
	cin >> T;

	int input_node;

	for (int count = 0; count < T; count++) {
		cin >> n;

		deque<int> preorder;
		deque<int> inorder;

		for (int inner_count = 0; inner_count < n; inner_count++) {
			cin >> input_node;
			preorder.push_back(input_node);
		}
		for (int inner_count = 0; inner_count < n; inner_count++) {
			cin >> input_node;
			inorder.push_back(input_node);
		}
		tree tr;
		tr.setHead(preorder.front());
		makeTree(tr.getHead(), preorder, inorder);
		tr.postorder();
	}
}