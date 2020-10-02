#include <stdio.h>
#include <stdlib.h>


struct node
{
 int data;
 struct node *link;
};

struct node *start=NULL;
struct node *temp,*nod, *front, *rear;


void insert_lnkq(struct node * );
void del_lnkq();
void display();


int main(void)
{
 int opt;
 
 do
 {
  printf("\n     1.Insert element into linked queue\n");
  printf("\n     2.Delete element from linked queue\n");
  printf("\n     3.Display queue contents\n");
  printf("\n     4.Quit\n");
  
  printf("\nEnter option:   ");
  scanf("%d",&opt);

  switch(opt)
  {
   case 1:
          nod=(struct node *)calloc(1,sizeof(struct node));
          insert_lnkq(nod);
          break;

   case 2:
          del_lnkq();
          break;

   case 3:
          display();
          break;

   case 4:
          exit(1);
  }
 } while(1);
 
}

void insert_lnkq(struct node *r)       
{
  int item;
  printf("\nEnter the element that has to be inserted:    ");
  scanf("%d",&item); 
  
  r->data=item;                        
  r->link=0;
  
 if(start==NULL)           
               { start= r; 
                 front =r;
                 rear=r;
               }  
 else   {rear->link= r; 
         rear =r;
        } 
}
 


void del_lnkq()                                      
{
 if(start==NULL)
     printf("\nQueue is empty! Deletion  not possible!\n");
 else
 {
  temp = start;
  start = start->link;
  front = start;
  free(temp);
 }
}

void display()                                  
{
 if(start == NULL)
  printf("\n Queue  is empty!    \n");
 else
 {printf("contents of the Queue:    \n");
  temp=start;
  while(temp->link !=0)
  {
   printf("\n  %d  ",temp->data);
   temp=temp->link;
  }
  printf("\n  %d  ",temp->data);
 }
}

