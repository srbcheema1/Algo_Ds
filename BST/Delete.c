#include<stdio.h>
#include<stdlib.h>

struct tree{
		int data;
		struct tree *left;
		struct tree *right;
}*root=NULL,*newn;

struct tree* create(int n)
{
	newn=(struct tree*)malloc(sizeof(struct tree));
	newn->data=n;
	newn->left=NULL;
	newn->right=NULL;
	return newn;
}

struct tree* ins(struct tree*r,int dat)
{
	if(r==NULL)
		return create(dat);
	if(dat < r->data)
		r->left=ins(r->left,dat);
	else if(dat > r->data)
		r->right=ins(r->right,dat);
	return r;
}

int max=-10000,min=10000;

void preorder(struct tree* n)
{
	if(n==NULL)
		return;
	else
	{
	preorder(n->left);
	preorder(n->right);
	printf("Deleting Node:%d\n",n->data);
	free(n);
	}
}
int flag=0;

void main()
{
	int choice=1,t,ne, exit;
	printf("Enter Root Node:\n");
	scanf("%d",&ne);
	root=ins(root,ne);
	while(choice!=0)
	{
		printf("Enter Value:\n");
		scanf("%d",&t);
		ins(root,t);
		printf("Want to Continue the tree:1 or 0...?\n");
		scanf("%d",&choice);
	}
	preorder(root);
	scanf("%d", exit);
}
