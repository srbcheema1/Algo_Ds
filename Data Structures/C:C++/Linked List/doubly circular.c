/*
	***********************
	Author   : Vivek Shah
	Question : Doubly Circular LL
	***********************
*/

#include<stdio.h>
#include<stdlib.h>
#include <string.h>

struct node
{
	char name[100];
	int roll;
	float cgpa;
	struct node* next;
	struct node* pre;
};

struct node* head;
struct node* last;
void display();

struct node* getNode(){
	char name[100];
	int roll;
	float cgpa;
	printf("Enter name to be inserted\n");
	printf("Enter Roll to be inserted\n");
	printf("Enter CGPA to be inserted\n");
	scanf("%s",name);
	scanf("%d",&roll);
	scanf("%f",&cgpa);
	struct node* temp = (struct node*)malloc(sizeof(struct node)) ;
	strcpy(temp->name,name);
	temp->roll=roll;
	temp->cgpa=cgpa;
	temp->next = NULL;
	temp->pre = NULL;
	return temp;
}

int countNode(){
	struct node* temp = head;
	int c = 0;

	if (head==NULL)
	{
		return 0;
	}

	do{
		c++;
		temp = temp->next;
	}while(temp!=head);

	return c;
}


void insert_beg(){
	struct node* temp = getNode();
	if (head==NULL)
	{
		temp->next=temp;
		temp->pre=temp;
	}
	else{
		temp->next=head;
		head->pre = temp;
		temp->pre = last;
		last->next=temp;
	}
	head = temp;
	last = head->pre;
	/*struct node* temp = getNode();
	temp->next = head;
    struct node* last = head->pre; 
    struct node* new_node = getNode();
    new_node->next = head;
    new_node->pre = last;
    last->next = head->pre = new_node;
    head = new_node;*/
    
	display();
}

void insert_btw(){//problem hai...
	printf("Enter the Node no. after wise Node is to be inserted\n");
	int ch;
	scanf("%d",&ch);
	printf("The total count of nodes is %d",countNode());
	int count = 0;
	if (ch<=0 || ch>countNode())
	{
		printf("INVALID NODE No.\n");
		return;
	}
	
	struct node* temp = getNode();
	struct node* t = head;

	do{
		count++;
		t=t->next;
	}while(t!=head || count!=ch-1);
/*
	printf("The value of count is %d",count);
	printf("\n************************************************\n");
	printf("Name    : %s\n",t->name);
	printf("Roll No : %d\n",t->roll);
	printf("CGPA 	: %f\n",t->cgpa);
*/
	temp->pre = t;
	temp->next = t->next;
	if(t==last){
		temp->next=head;
		last=temp;
	}
	else t->next->pre = temp;
	t->next = temp;
    display();
}

void insert_end(){
	struct node* temp = getNode();

	if (head == NULL){
		temp->next=temp;
		temp->pre=temp;
		head = temp;
		last = head->pre;
	}

	else{
		temp->next=last->next;
		temp->pre = last;
		last->next = temp;
		last = temp;
		last->next = head;
	}
	display();
}


void delete_beg(){
	if (head==NULL)
	{
		printf("Nothing to Delete\n");
	}
	else if (head==last)
	{
		head=NULL;
		last=NULL;
	}
	else{
		head=head->next;
		head->pre=NULL;
		last->next=head;
	}
	display();
}


void delete_btw(){
	printf("Enter the Node no. to be deleted\n");
	int ch;
	scanf("%d",&ch);
	int count = 0;
	if (ch<=0 || ch>countNode())
	{
		printf("INVALID NODE No.\n");
		return;
	}
    else{
    	if(ch==1){
    		head=NULL;
    		last=NULL;
    		return;
		}
    	int c=0;
		struct node* t = head;
		int f=0;
		while(t!=NULL){
			c++;
			if (c==ch)
			{
				f=1;
				break;
			}
			t = t->next;
		}
		if (f==0)
		{
			printf("NOT FOUND\n");
		}
		if (t==last)
		{
			last = last->pre;
			last->next=head;
		}
		else 
		{
			t->pre->next = t->next;
			t->next->pre = t->pre;
		}
	}
	display();
}

void delete_end(){
	if (last==NULL)printf("Nothing to Delete\n");
	else if(head==last){
		head=NULL;
		last=NULL;
	}
	else{
		last = last->pre;
		last->next = head;
	}
	display();
}


void search(){
	int sc;
	printf("Enter a roll no to be Searched\n");
	scanf("%d",&sc);
	if (head==NULL)
	{
		printf("No data to search\n");
		return;
	}
	else{
		struct node* temp = head;
		int f=0;
		do{
			if(temp->roll==sc){f=1;break;}
			temp = temp->next;
		}while(temp!=head);
		if(f==0)printf("No data found\n");
		else{
			printf("FOUND THE DATA\n");
			printf("\n%s\n%d\n%f\n",temp->name,temp->roll,temp->cgpa);
		}
	}
}

void display(){
	if(head==NULL){printf("Nothing to display\n");return;}
	struct node* temp = head;
	do{
		printf("\n************************************************\n");
		printf("Name    : %s\n",temp->name);
		printf("Roll No : %d\n",temp->roll);
		printf("CGPA 	: %f\n",temp->cgpa);
		temp = temp->next;
	}while(temp!=head);
	printf("\n************************************************\n\n");
}

int main()
{
	head = NULL;
	last = NULL;
	int i,ch;
	while(1){
        printf("1.Insert\n2.Delete\n3.Search\n4.Display\n");
        scanf("%d",&i);
        if (i==1)
        {
            printf("1.Insert Begin\n2.Insert Between\n3.Insert End\n");
            scanf("%d",&ch);
            if (ch==1)
                insert_beg();
            else if (ch==2)
            	insert_btw();
            else if(ch==3)
                insert_end();
            else printf("Invalid Choice\n");

        }
        else if (i==2)
        {
            printf("1.Delete Begin\n2.Delete Between\n3.Delete End\n");
            scanf("%d",&ch);
            if (ch==1)
                delete_beg();
            else if (ch==2)
            	delete_btw();
            else if(ch==3)
                delete_end();
            else printf("Invalid Choice\n");
        }
        else if(i==3){
        	search();
        }

        else if(i==4){
            display();
        }
        else printf("Invalid Choice\n");
	}
	return 0;
}
