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
void Preo(struct tree* n)
{
	if(n==NULL)
		return;
	if(n->data>max)
		max=n->data;
	if(n->data<min)
		min=n->data;
	//printf("%d ",n->data);
	Preo(n->left);
	Preo(n->right);
}
void main()
{
	int choice=1,t,ne, exit;
	printf("Enter Root Node:\n");
	scanf("%d",&ne);
	root=ins(root,ne);
	while(choice!=0)
	{
		printf("Enter Data:\n");
		scanf("%d",&t);
		ins(root,t);
		printf("Want to Continue the tree:1 or 0...?\n");
		scanf("%d",&choice);
	}
	Preo(root);
	printf("Minimum:%d\n",min);
	printf("Maximum:%d\n",max);
	scanf("%d", exit);
}
