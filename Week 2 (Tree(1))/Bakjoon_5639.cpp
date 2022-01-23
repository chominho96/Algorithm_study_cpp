#include <iostream>

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
	node* head;
public:
	tree() : head(NULL) {

	}
	bool isEmpty() {
		return head == NULL;
	}
	void setHead(node* n) {
		head = n;
	}
	node* getHead() {
		return head;
	}

	void postorder(node* n) {
		if (n == NULL) {
			return;
		}
		else {
			postorder(n->getLeft());
			postorder(n->getRight());
			cout << n->getData() << endl;;
		}
	}
	void postorder() {
		if (isEmpty()) {
			cout << "ERROR : tree is empty";
			return;
		}
		else {
			postorder(head);
		}
		cout << endl;
	}
	void insert(int data) {
		node* current = head;
		while (true) {
			if (data > current->getData()) {
				if (current->getRight() == NULL) {
					current->setRight(new node(data));
					break;
				}
				else {
					current = current->getRight();
				}
			}
			else {
				if (current->getLeft() == NULL) {
					current->setLeft(new node(data));
					break;
				}
				else {
					current = current->getLeft();
				}
			}
		}
	}




};

int main() {
	tree tr;
	
	int input_num;
	cin >> input_num;
	tr.setHead(new node(input_num));
	// push head


	while (true) {
		cin >> input_num;
		if (cin.eof()) {
			break;
		}
		
		tr.insert(input_num);

	}
	tr.postorder();
	

}