/*
	***********************
	Author   : Vivek Shah
	Question : Doubly LL
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

	while(temp!=NULL){
		c++;
		temp = temp->next;
	}

	return c;
}


void insert_beg(){
	struct node* temp = getNode();
	temp->next = head;
	if(head!=NULL){
		head->pre = temp;
	}
	head = temp;
	display();
}

void insert_btw(){
	printf("Enter the Node no. after wise Node is to be inserted\n");
	int ch;
	scanf("%d",&ch);
	int count = 0;
	if (ch<=0 || ch>countNode())
	{
		printf("INVALID NODE No.\n");
		return;
	}
    else{
		struct node* temp = getNode();
		struct node* t = head;

		while(t!=NULL && t!=ch){
			t=t->next;
		}	
		temp->pre = t;
		temp->next = t->next;
		t->pre->next = temp;
		if(t->next!=NULL)t->next->pre = temp;
	    display();
    }
}

void insert_end(){
	struct node* temp = getNode();

	if (head == NULL)
		head = temp;

	else{
		struct node* t = head;
		while(t->next!=NULL)
			t = t->next;
		t->next = temp;
		temp->pre = NULL;
	}
	display();
}


void delete_beg(){
	if (head==NULL)
	{
		printf("Nothing to Delete\n");
	}
	else{
		head=head->next;
		head->pre=NULL;
	}
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
		else if (t->next!=NULL)
		{
			t->pre->next = t->next;
			t->next->pre = t->pre;
		}
		else{
			t->pre->next = NULL;
		}
	}
}

void delete_end(){
	if (head==NULL)printf("Nothing to Delete\n");
	else if(head->next==NULL)head=NULL;
	else{
		struct node* t = head;
		while(t->next->next!=NULL)
			t = t->next;
		t->next=NULL;
	}
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
		while(temp!=NULL){
			if(temp->roll==sc){f=1;break;}
			temp = temp->next;
		}
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
	while(temp!=NULL){
		printf("\n************************************************\n");
		printf("Name    : %s\n",temp->name);
		printf("Roll No : %d\n",temp->roll);
		printf("CGPA 	: %f\n",temp->cgpa);
		temp = temp->next;
	}
	printf("\n************************************************\n\n");
}

int main()
{
	head = NULL;
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
