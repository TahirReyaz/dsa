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
	Node * root = new Node(d);
	
	q.push(root);
	q.push(NULL);

	while(!q.empty()) {
		Node * temp = q.front();
		q.pop();
		if(temp != NULL) {
			// Input left
			cin>>d;
			if(d == -1) {
				temp->left = NULL;
			} else {
				Node * temp2 = new Node(d);
				temp->left = temp2;
				q.push(temp2);
			}			
			
			// Input right
			cin>>d;
			if(d == -1) {
				temp->right = NULL;
			} else {
				Node * temp2 = new Node(d);
				temp->right = temp2;
				q.push(temp2);
			}
		} else {
			if(!q.empty()) {
				q.push(NULL);
			}
		}
	}
	
	return root;
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


vector<int> printKthLevel(Node* root, int k){
   // your code goes here
   vector<int> ans;
   queue<Node *> q;
   q.push(root);
   q.push(NULL);
   
   while(!q.empty()) {
       Node * temp = q.front();
       if(k==1) {
           while(q.front() != NULL){
			   ans.push_back(q.front()->data);
               q.pop();
           }
		   return ans;
       }
       q.pop();
       if(temp == NULL) {
			k--;
           if(!q.empty()) {
               q.push(NULL);
           }
       } else {
           if(temp->left) {
               q.push(temp->left);
           }
           if(temp->right) {
               q.push(temp->right);
           }
       }
   }
   return ans;  
}

int heightOfTree(Node * root) {
	if(root == NULL) {
		return 0;
	}
	
	int h1 = heightOfTree(root->left);
	int h2 = heightOfTree(root->right);
	
	return 1 + max(h1, h2);
}

int sumOfTree(Node* root) {
    if(root == NULL) {
        return 0;
    }
	int sum = 0;    
    if(root->left) {
        sum+= sumOfTree(root->left);
    }
    if(root->right) {
        sum+= sumOfTree(root->right);
    }
    return sum + root->data;
}

void printVector(vector<int> v) {
	cout<<"[";
	for(auto x: v) {
		cout<<x<<", ";
	}
	cout<<"]"<<endl;
}

int diameter(Node * root) {
	if(root == NULL) {
		return 0;
	}
	int lh=0, rh=0, ld=0, rd=0;
	if(root->left) {
		lh = heightOfTree(root->left);
		ld = diameter(root->left);
	}
	if(root->right) {
		rh = heightOfTree(root->right);
		rd = diameter(root->right);
	}
		
	return max(max(ld, rd), lh+rh);
}

pair<int, int> diameterOptimised(Node * root) {
	pair<int, int> dim;
	if(root == NULL) {
		dim.first = dim.second = 0;
		return dim;
	}
	pair<int, int> left = {0, 0}, right = {0, 0};
	if(root->left) {
		left = diameterOptimised(root->left);
	}
	if(root->right) {
		right = diameterOptimised(root->right);
	}
	
	dim.second = max(left.second, right.second) + 1;	
	dim.first = max(left.second + right.second, max(left.first, right.first));
	
	return dim;
}

int main() {
	Node * root = buildTree();
	// Node * root = buildTreeLevelOrder();
	int k=2;

	cout<<k<<"th level: ";
	vector<int> kthLevel = printKthLevel(root, k);
	printVector(kthLevel);
	
	cout<<"Sum of tree: "<<sumOfTree(root)<<endl;
	
	cout<<"Diameter: "<<diameter(root)<<endl;
	pair<int, int> diameterNHeight = diameterOptimised(root);
	cout<<"Diameter optimised: "<<diameterNHeight.first<<endl;
	
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
	
	cout<<"Height of Tree: "<<heightOfTree(root);

	return 0;
}