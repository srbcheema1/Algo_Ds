/******************************************
*    AUTHOR         :   VIVEK SHAH        *
*    INSTITUTION    :   NIT SURAT         *
******************************************/

#include <bits/stdc++.h>
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long int
#define mod 1000000007
#define rep(i,a,b) for (ll i = a; i<b; ++i)

using namespace std;

struct node
{
	int data;
	struct node* left;
	struct node* right;
};

struct node* getNode(int data){
	struct node* tmp = new node();
	tmp->data = data;
	tmp->left = NULL;
	tmp->right = NULL;
	return tmp;
}

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

int search(struct node* root, int data){
	if (root==NULL)
	{
		return 0;
	}
	else if (root->data = data)
	{
		return 1;
	}
	else if (data<=root->data)
	{
		return search(root->left,data);
	}
	else{
		return search(root->right,data);
	}
}

int main()
{
	boost;
	struct node* root = NULL;
	root = insert(root,15);
	root = insert(root,10);
	root = insert(root,20);
	if(search(root,15)){
		cout<<"Found";
	}
	else cout<<"Not Found";
	return 0;
}