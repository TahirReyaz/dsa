#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Input: 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
// Input Level Order: 1 2 3 4 5 -1 6 -1 -1 7 -1 -1 -1 -1 -1

class Node {
	public:
	int data;
	Node *left;
	Node *right;

	Node(int d) {
		data = d;
		left = right = NULL;
	}
};

Node * buildTree() {

	int d;
	cin>>d;

	if(d == -1) {
		return NULL;
	}

	Node * n = new Node(d);
	n->left = buildTree();
	n->right = buildTree();
	return n;
}

Node * buildTreeLevelOrder() {
	int d;
	cin>>d;

	queue<Node *> q;

	while()
	Node * n = new Node(d);
	q.push(n);

}

void printPreorder (Node * root) {
	if(root == NULL) {
		return;
	}
	cout<<root->data<<" ";
	printPreorder(root->left);
	printPreorder(root->right);
}

void printInorder (Node * root) {
	if(root == NULL) {
		return;
	}
	printInorder(root->left);
	cout<<root->data<<" ";
	printInorder(root->right);
}

void printPostorder(Node * root) {
	if(root == NULL) {
		return;
	}
	printPostorder(root->left);
	printPostorder(root->right);
	cout<<root->data<<" ";
}

void printLevelOrder(Node * root) {

	queue<Node *> q;
	q.push(root);
	q.push(NULL);

	while(!q.empty()) {
		Node * temp = q.front();
		if(temp == NULL) {
			cout<<endl;
			q.pop();
			if(!q.empty())
				q.push(NULL);
		} else {
			q.pop();
			cout<<temp->data<<" ";
			if(temp->left) {
				q.push(temp->left);
			}
			if(temp->right) {
				q.push(temp->right);
			}
		}
	}
	
}

int main() {
	// Node * root = buildTree();
	Node * root = buildTreeLevelOrder();

	cout<<"Pre: ";
	printPreorder(root);
	cout<<endl;

	cout<<"In: ";
	printInorder(root);
	cout<<endl;

	cout<<"Post: ";
	printPostorder(root);
	cout<<endl;

	cout<<"Level order:\n";
	printLevelOrder(root);
	cout<<endl;

	return 0;
}