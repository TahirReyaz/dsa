#include <bits/stdc++.h>
using namespace std;
 
struct Node {
    int key;
    Node* left, *right;
};

vector<int> printKthLevel(Node* root, int k){
    // your code goes here
  // your code goes here
   vector<int> ans;
   queue<Node *> q;
   q.push(root);
   q.push(NULL);
   
   while(!q.empty()) {
       Node * temp = q.front();
       if(k==0) {
           while(q.front() != NULL){
			   ans.push_back(q.front()->key);
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