#include <iostream>
#include <vector>
constexpr auto MAX_SIZE = 10001;

using namespace std;

vector<int> MAP[MAX_SIZE];
bool visited[MAX_SIZE];

int width[MAX_SIZE][2]{ 0 };

int DX = 1;

class node {
	int data;
	node* left;
	node* right;
	int dx;
	int depth;
public:
	node(int d, node* l, node* r, int dep) : data(d), left(l), right(r), dx(-1), depth(dep) {

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
	int getDX() {
		return dx;
	}
	void setDX(int d) {
		dx = d;
	}
	int getDepth() {
		return depth;
	}
};

class tree {
	node* root;
	int size;
	int height;
public:
	tree() : root(NULL), size(0), height(0) {

	}
	bool isEmpty() {
		return size == 0;
	}
	int getHeight() {
		return height;
	}
	node* getRoot() {
		return root;
	}
	void inorder(node* n) {
		if (n == NULL || n->getData() == -1) {
			return;
		}
		inorder(n->getLeft());
		n->setDX(DX);

		// calculate max width
		if (width[n->getDepth()][0] == 0) {
			width[n->getDepth()][0] = DX;
			width[n->getDepth()][1] = DX;
		}
		else if (width[n->getDepth()][1] < DX) {
			width[n->getDepth()][1] = DX;
		}

		DX++;
		inorder(n->getRight());
	}
	void inorder() {
		inorder(root);
	}
	void make_tree(node* n) {
		if (n == NULL || n->getData() == -1) {
			return;
		}
		if (n->getDepth() > height) {
			height = n->getDepth();
		}

		int left = MAP[n->getData()][0];
		int right = MAP[n->getData()][1];
		n->setLeft(new node(left, NULL, NULL, n->getDepth() + 1));
		make_tree(n->getLeft());
		n->setRight(new node(right, NULL, NULL, n->getDepth() + 1));
		make_tree(n->getRight());
	}
	void make_tree(int r) {
		root = new node(r, new node(MAP[r][0], NULL, NULL, 2), new node(MAP[r][1], NULL, NULL, 2), 1);
		make_tree(root->getLeft());
		make_tree(root->getRight());
	}
	int find() {
		
	}
};

int main() {
	int N, par, left, right;

	cin >> N;
	// initialize visited
	for (int index = 1; index < MAX_SIZE; index++) {
		visited[index] = false;

	}
	for (int count = 0; count < N; count++) {
		cin >> par >> left >> right;
		MAP[par].push_back(left);
		MAP[par].push_back(right);
		visited[left] = true;
		visited[right] = true;
	}

	// find root
	int root;
	for (int index = 1; index < MAX_SIZE; index++) {
		if (!visited[index]) {
			root = index;
			break;
		}
	}

	// make tree
	tree tr;
	tr.make_tree(root);

	// calculate dx
	tr.inorder();


	// calculate max width
	int max_width = 1;
	int max_depth = 1;
	
	for (int depth = 2; depth <= tr.getHeight(); depth++) {
		if (width[depth][1] - width[depth][0] + 1 > max_width) {
			max_width = width[depth][1] - width[depth][0] + 1;
			max_depth = depth;
		}
	}

	cout << max_depth << " " << max_width << endl;

}