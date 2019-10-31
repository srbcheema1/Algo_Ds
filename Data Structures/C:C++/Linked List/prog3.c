#include<stdlib.h>
#include<Stdio.h>
typedef struct  node{
int data;
struct node*next,*prev;
}node;
void main()
{ node*head,*p,*q,*r;
 int i,n,ch,x,loc;
 printf("Enter the number of nodes\n");
 scanf("%d",&n);
head=(node*)malloc(sizeof(node));
printf("Enter data for first node\n");
scanf("%d",&head->data);
head->next=head->prev=NULL;
q=head;
for(i=0;i<n-1;i++)
{ p=(node*)malloc(sizeof(node));
q->next=p;
p->prev=q;
p->next=NULL;
printf("enter data for new node\n");
scanf("%d",&p->data);
q=q->next;
}
// PRINTING
p=head;
while(p!=NULL)
{ printf("%d\t",p->data);
p=p->next;
}
do{
    printf("\nEnter 1:FOR FRONT, 2: END, 3: MIDDLE, 4:PRINT FOR DELETION\n");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1: //FRONT
         p=head;
         head=head->next;
         free(p);
         head->prev=NULL;
        break;
    case 2: // END
         q=head;
         while(q->next!=NULL)
         {   q=q->next;
         }
         (q->prev)->next=NULL;
         free(q);
         break;
    case 3: //MIDDLE
         q=head;
         printf("enter location of insertion\n");
         scanf("%d",&loc);
         for(i=1;i<=loc-2;i++)
         {  q=q->next;
         }
         r=q->next;
         q->next=r->next;
         (r->next)->prev=q;
         free(r);
         break;
    case 4: //PRINTING
        p=head;
        while(p!=NULL)
        { printf("%d\t",p->data);
          p=p->next;
        }
        break;
    default: printf("Error\n");
    }
    printf("Press 1 to repeat\n");
    scanf("%d",&x);
}while(x==1);
}

