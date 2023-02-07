#include <bits/stdc++.h>
using namespace std;
 
struct Node {
    int key;
    Node* left, *right;
};

int sumBT(Node* root)
{
    if(root == NULL) {
        return 0;
    }
	int sum = 0;

    if(root->left) {
        sum+= sumBT(root->left);
    }
    if(root->right) {
        sum+= sumBT(root->right);
    }
    return sum + root->key;
}