#include <iostream>

using namespace std;

class node {
	char data;
	node* left;
	node* right;
public:
	node(char d) : data(d), left(NULL), right(NULL) {

	}
	char getData() {
		return data;
	}
	void setData(char d) {
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
	void inorder(node* n) {
		// left - root - right

		if (n == NULL) {
			return;
		}
		else {
			inorder(n->getLeft());
			cout << n->getData();
			inorder(n->getRight());
		}
	}
	void inorder() {
		if (isEmpty()) {
			cout << "ERROR : tree is empty";
			return;
		}
		else {
			inorder(head->getLeft());
			cout << head->getData();
			inorder(head->getRight());
		}
		cout << endl;
	}
	void preorder(node* n) {
		if (n == NULL) {
			return;
		}
		else {
			cout << n->getData();
			preorder(n->getLeft());
			preorder(n->getRight());
		}
	}
	void preorder() {
		// root - left - right
		if (isEmpty()) {
			cout << "ERROR : tree is empty";
			return;
		}
		else {
			preorder(head);
		}
		cout << endl;

	}
	void postorder(node* n) {
		if (n == NULL) {
			return;
		}
		else {
			postorder(n->getLeft());
			postorder(n->getRight());
			cout << n->getData();
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



	node* find(node* n, char d) {
		if (n == NULL) {
			return NULL;
		}
		else {
			if (n->getData() == d) {
				return n;
			}
			else {
				if (find(n->getLeft(), d) != NULL) {
					return find(n->getLeft(), d);
				}
				else {
					return find(n->getRight(), d);
				}
			}
		}
	}
	void insert(char root, char l, char r) {
		node* result;
		if (isEmpty()) {
			setHead(new node(root));
			result = head;
		}
		else {
			result = find(head, root);
		}
		
		if (result->getLeft() == NULL && l != '.') {
			result->setLeft(new node(l));
		}
		if (result->getRight() == NULL && r != '.') {
			result->setRight(new node(r));
		}
	}

};

int main() {
	int N;
	cin >> N;

	char cur, l, r;

	tree tr;
	
	for (int count = 0; count < N; count++) {
		cin >> cur >> l >> r;
		tr.insert(cur, l, r);
	}
	tr.preorder();
	tr.inorder();
	tr.postorder();

}