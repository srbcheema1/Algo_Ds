#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<malloc.h>
//structure of node
struct node{
int data;
struct node* left;
struct node* right;
};
struct node* root;
//insertion into bst
struct node* insert(struct node *rootptr,int data)
{
    if(rootptr==NULL)
    {
        rootptr=(struct node*)malloc(sizeof(struct node));
        rootptr->data=data;
        rootptr->left=NULL;
        rootptr->right=NULL;
        return;
    }
    else if(data<=rootptr->data)
    {
        rootptr->left=insert(rootptr->left,data);
    }
    else if(data>= rootptr->data)
    {
        rootptr->right=insert(rootptr->right,data);
    }
    return rootptr;
}
//inorder transversal of tree
void inorder(struct node* rootptr)
{
    if(rootptr==NULL)
    return;
    inorder(rootptr->left);
    printf("%d ",rootptr->data);
    inorder(rootptr->right);
}
//to print a level of tree
void printGivenLevel(struct node* root, int level, int ltr)
{
    if(root == NULL)
        return;
    if(level == 1)
        printf("%d ", root->data);
    else if (level > 1)
    {
        if(ltr)
        {
            printGivenLevel(root->left, level-1, ltr);
            printGivenLevel(root->right, level-1, ltr);
        }
        else
        {
            printGivenLevel(root->right, level-1, ltr);
            printGivenLevel(root->left, level-1, ltr);
        }
    }
}
//to find height of tree
int height(struct node* node)
{
    if (node==NULL)
        return 0;
    else
    {

        int lheight = height(node->left);//to find height of left subtree
        int rheight = height(node->right);//to find height of right subtree


        if (lheight > rheight)
            return(lheight+1);
        else return(rheight+1);
    }
}
//for spiral transversal of tree
void printSpiral(struct node* root)
{
    int h = height(root);
    int i;

    /*ltr -> Left to Right. If this variable is set,
      then the given level is traverseed from left to right. */
    bool ltr = false;
    for(i=1; i<=h; i++)
    {
        printGivenLevel(root, i, ltr);

        /*Revert ltr to traverse next level in opposite order*/
        ltr = !ltr;
    }
}

main()
{
    root=NULL;
    int n,data;
    while(1)
   {
    printf("1.insert\n2.display\n3.Spiral Order traversal\n4.exit\nenter choice\n");
    scanf("%d",&n);
    switch(n)
    {
        case 1: printf("enter data");
                scanf("%d",&data);
                root=insert(root,data);
                break;
        case 2:inorder(root);
                break;
        case 3:printf("Spiral Order traversal of binary tree is \n");
                printSpiral(root);

        case 4:return;
    }
   }
}
