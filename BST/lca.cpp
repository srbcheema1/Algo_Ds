/*
	Author: Pritish Thakkar
	Codechef : joe001
	Blog : http://sleepincode.blogspot.com
*/

/// SUMMARY: 
/// The lowest common ancestor between two nodes n1 
/// and n2 is defined as the lowest node in BST that 
/// has both n1 and n2 as descendants (where we allow
/// a node to be a descendant of itself).

// This contains almost all headers required during 
// competitive programming contests, and that's why used
// by every best coder out there..
#include<bits/stdc++.h>

using namespace std;

// Structure if a node in BST
struct node{
	int data;
	struct node* left;
	struct node* right;
};

// Returns a new whenever required
struct node* getNode(int data){
	struct node* tmp = new node();
	tmp->data = data;
	tmp->left = NULL;
	tmp->right = NULL;
	return tmp;
}

// Function to insert the elements in a BST
struct node* insert(struct node* root,int data){
	if (root==NULL)
	{
		root = getNode(data);
	}
	else if (data <= root->data)
	{
		root->left = insert(root->left,data); 
	}
	else{
		root->right = insert(root->right,data);
	}
	return root;
}


// Returns the value of LCA node.
int lca(node* root, int val1, int val2){
	// If boths values are smaller than current node value
	// it means LCA is present in left subtree.
	if(root->data > val1 && root->data > val2){
		return lca(root->left, val1, val2);
	}

	// If boths values are greater than current node value
	// it means LCA is present in right subtree.
	if(root->data < val1 && root->data < val2){
		return lca(root->right, val1, val2);
	}

	// Now, one is in left subtree and other in right subtree
	// return current node value.
	return root->data;
}

int main(){
	struct node* root = NULL;
	
	// Inserting the values in the BST
	root = insert(root,15);
	root = insert(root,10);
	root = insert(root,20);
	root = insert(root,16);
	root = insert(root,17);
	root = insert(root,12);

	cout << lca(root, 12, 17) << endl;

	// OUTPUT : 15
}