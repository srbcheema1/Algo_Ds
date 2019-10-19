#include<stdio.h>
#include<stdlib.h>

struct tree{
		int data;
		struct tree* left;
		struct tree* right;
};

struct tree* create(int dat)
{
	struct tree* n=(struct tree*)malloc(sizeof(struct tree));
	n->data=dat;
	n->left=NULL;
	n->right=NULL;
	return n;
}

int height(struct tree* n)
{
	int l,r;
	if(n==NULL)
		return 0;
	else
	{
		l=height(n->left);
		r=height(n->right);
		if(l>r)
			return(l+1);
		else
			return (r+1);
	}
}

int count=0;

int node(struct tree* n)
{
	if(n==NULL)
		return count;
	else
	{
		node(n->left);
		node(n->right);
		count++;
	}
	
}

void main()
{
	struct tree* root;
	int ans, exit;
	root=create(30);
	ans=height(root);
	printf("Height of tree after first insertion: %d\n",ans);
	root->left=create(20);
	root->right=create(40);
	root->left->left=create(60);
	ans=height(root);
	printf("Height of given tree: %d\n",ans);
	ans=node(root);
	printf("No. of nodes: %d\n",ans);
	scanf("%d", exit);
}
