#include <bits/stdc++.h> 
using namespace std; 

class node 
{ 
	public: 
	int data; 
	int liss; 
	node *left, *right; 
}; 

int max(int x, int y)
{
	return (x > y) ? x : y;
} 

int LISS(node *root) 
{ 
	if (root == NULL) 
		return 0; 

	if (root->liss) 
		return root->liss; 

	if (root->left == NULL && root->right == NULL) 
		return (root->liss = 1); 

	int liss_exc = LISS(root->left) + LISS(root->right); 

	int liss_inc= 1; 
	if (root->left) 
		liss_inc+= LISS(root->left->left) + LISS(root->left->right); 
	if (root->right) 
		liss_inc+= LISS(root->right->left) + LISS(root->right->right); 

	root->liss = max(liss_inc, liss_exc); 

	return root->liss; 
} 

node* newNode(int data) 
{ 
	node* temp = new node(); 
	temp->data = data; 
	temp->left = temp->right = NULL; 
	temp->liss = 0; 
	return temp; 
} 

int main() 
{ 
	node *root= newNode(20); 
	root->left= newNode(8); 
	root->left->left= newNode(4); 
	root->left->right= newNode(12); 
	root->left->right->left= newNode(10); 
	root->left->right->right= newNode(14); 
	root->right= newNode(22); 
	root->right->right= newNode(25); 

	cout << "Size of the Largest Independent Set is " << LISS(root); 

	return 0; 
} 
