
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};
int main()
{
    struct node *head=(struct node*)malloc(sizeof(struct node));
    int n,num,i;
    printf("Enter the number of nodes\n");
    scanf("%d",&n);
    printf("Enter the data for the first node\n");
    scanf("%d",&num);
    struct node *t,*current;
    head->data=num;
    head->link=NULL;
    t=head;
    for(i=2;i<=n;i++)
    {
        current=(struct node*)malloc(sizeof(struct node));
        printf("Enter the data for the next node\n");
        scanf("%d",&num);
        current->data=num;
        current->link=NULL;
        t->link=current;
        t=t->link;
    }
    int c=n/2;
    struct node *head1=(struct node*)malloc(sizeof(struct node));
    head1->data=head->data;
    head1->link=NULL;
    t=head;
    t=t->link;
    struct node *t1;
    t1=head1;
    
    for(i=2;i<=c;i++)
    {
        current=(struct node*)malloc(sizeof(struct node));
        current->data=t->data;
        current->link=NULL;
        t1->link=current;
        t1=t1->link;
        t=t->link;
    }
    
    struct node *head2=(struct node*)malloc(sizeof(struct node));
    head2->data=t->data;
    head1->link=NULL;
    t=t->link;
    t1=head2;
    
    for(i=c;i<=n;i++)
    {
        current=(struct node*)malloc(sizeof(struct node));
        current->data=t->data;
        current->link=NULL;
        t1->link=current;
        t1=t1->link;
        t=t->link;
    }
    t=head1;
    for(i=1;i<=c;i++)
    {
        printf("%d=%d\n",i,t->data);
        t=t->link;
        
    }

    t=head2;
    for(i=c;i<=(n-c);i++)
    {
        printf("%d=%d\n",i,t->data);
        t=t->link;
        
    }

    return 0;
}