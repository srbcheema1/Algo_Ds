#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct node
{
    int data;
    struct node *next;
};
struct node*p=NULL;
struct node*q=NULL;
int j=0,k=0;

struct node* create(struct node*current)
{
  struct node *new_node;
  new_node=(struct node *)malloc(sizeof(struct node));

  printf("\nEnter the data : ");
  scanf("%d",&new_node->data);
  new_node->next=NULL;
  j=j+1;

  if(p==NULL)
  {
    p=new_node;
    current=new_node;
  }
  else
  {
  current->next=new_node;
  current=new_node;
  }
  return current;

}

struct node* create2(struct node*current)
{
  struct node *new_node;
  new_node=(struct node *)malloc(sizeof(struct node));

  printf("\nEnter the data : ");
  scanf("%d",&new_node->data);
  new_node->next=NULL;
  k=k+1;

  if(q==NULL)
  {
    q=new_node;
    current=new_node;
  }
  else
  {
    current->next=new_node;
    current=new_node;
  }
  return current;

}


void display(struct node*start)
{
    struct node *new_node;
    printf("\nThe Linked List : \n");
    new_node=start;
    while(new_node!=NULL)
    {
        printf("%d--->",new_node->data);
        new_node=new_node->next;
    }
    printf("NULL");
}
struct node* sort(struct node*s)
{
    int i;
    struct node *temp;
    for(i=0;i<j+k;i++)
    {
        s=p;
        while(s->next!=NULL)
        {
            if(s->data>s->next->data)
            {
                temp->data=s->data;
                s->data=s->next->data;
                s->next->data=temp->data;
            }
            s=s->next;
        }

   }

}
void con(struct node*p,struct node*q)
{
    while(p->next!=NULL)
    p=p->next;
    p->next=q;
}


main()
{
    int n;
    struct node* current1,*current2;
    current1=NULL;
    current2=NULL;
    while(1)
    {
        printf("1.insert list 1\n2.insert list 2\n3.display list 1\n4.display list 2\n5.sort\n6.display final list\n7.concatinate\n8.exit \nenter choice\n");
        scanf("%d",&n);

    switch(n){
    case 1: current1=create(current1);
            //p=current;
            break;
    case 2: current2=create2(current2);
            //q=current;
            break;
    case 3: display(p);
            break;
    case 4:display(q);
            break;
    case 5:sort(p);
            break;
    case 6: display(p);
            break;
    case 7:con(p,q);
            break;
    case 8: return;
    }
    }
}
