#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

class node {
	string data;
	vector<node*> child;
public:
	node(string str) : data(str) {

	}
	string getData() {
		return data;
	}
	void setData(string str) {
		data = str;
	}
	node* insertNode(string str) {
		// insert new node
		node* result = new node(str);
		child.push_back(result);
		return result;
	}
	node* find(string str) {
		for (int index = 0; index < child.size(); index++) {
			if (child[index]->data == str) {
				return child[index];
			}
		}
		return NULL;
	}
	vector<node*> getChild() {
		return child;
	}

};

bool cmp(node* n1, node* n2) {
	return n1->getData() < n2->getData();
}

class tree {
	node* head;
public:
	tree() : head(new node("")){
		// head node is dummy node
	}
	bool isEmpty() {
		return head == NULL;
	}
	node* getHead() {
		return head;
	}

	void insert(vector<string>& route) {
		node* current = head;
		for (int index = 0; index < route.size(); index++) {
			if (current->find(route[index]) == NULL) {
				current = current->insertNode(route[index]);
			}
			else {
				current = current->find(route[index]);
			}
		}
	}

	void print(node* n, string str) {
		vector<node*> current_child = n->getChild();

		cout << str << n->getData() << endl;

		if (current_child.empty()) {
			return;
		}
		else {
			// print current node
			sort(current_child.begin(), current_child.end(), cmp);
			for (int index = 0; index < current_child.size(); index++) {
				print(current_child[index], str + "--");
			}
		}

	}
	void print() {
		vector<node*> head_child = head->getChild();

		if (head_child.empty()) {
			return;
		}
		else {
			sort(head_child.begin(), head_child.end(), cmp);
			for (int index = 0; index < head_child.size(); index++) {
				print(head_child[index], "");
			}
		}
	}
	
};

int main() {
	int N, K;
	cin >> N;

	tree tr;

	string food;
	for (int count = 0; count < N; count++) {
		cin >> K;
		vector<string> route;
		for (int inner_count = 0; inner_count < K; inner_count++) {
			cin >> food;
			route.push_back(food);
		}
		tr.insert(route);
	}
	tr.print();
}