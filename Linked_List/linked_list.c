#include <stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
	int roll;
	char name[100];
	float cgpa;
	struct node* next;
};

struct node* head;

struct node* getNode(int roll1,char name1[], float cgpa1){
	struct node* p = (struct node*)malloc(sizeof(struct node));
	p->roll=roll1;
	strcpy(p->name,name1);
	p->cgpa=cgpa1;
	return p;
}

struct node* getLastNode(){
	struct node* temp = head;
	while(temp->next!=NULL)
		temp=temp->next;
	return temp;
}

int countNode(){
	struct node* temp = head;
	int count=0;
	while(temp!=NULL){
		count++;
		temp = temp->next;
	}
	return count;
}

void ins_beg(int roll,char name[], float cgpa){
	struct node* p =getNode(roll,name,cgpa);
	p->next = head;
	head = p;
}

void ins_btw(int roll,char name[], float cgpa,int pos){
	if (pos>0 && pos<=countNode())
	{
		struct node* temp = head;
		int count=0;
		while(count!=(pos-1)){
			temp = temp->next;
		}
		struct node* p = getNode(roll,name,cgpa);
		p->next = temp->next;
		temp->next=p;
	}
	else{
		printf("INVALID POSITIONS\n");
	}
}

void ins_end(int roll,char name[], float cgpa){
	struct node* p =getNode(roll,name,cgpa);
	if (head==NULL)//list is empty
	{
		head=p;
	}
	else{
		struct node* temp = head;
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next = p;
	}
}

void del_beg(){
	if(head==NULL)printf("NOTHING TO BE DELETED\n");
	else{
		head = head->next;	
	}
}

void del_btw(int pos){	
	if (pos>0 && pos<=countNode())
	{
		struct node* temp = head;
		int count=0;
		while(count!=(pos-1)){
			temp = temp->next;
		}			
		temp->next=temp->next->next;
	}
	else{
		printf("INVALID POSITIONS\n");
	}

}

void del_end(){
	if(head==NULL)printf("NOTHING TO BE DELETED\n");
	else if(head->next==NULL)head=NULL;
	else{
		struct node* temp = head;
		while(temp->next->next!=NULL)temp = temp->next;		
		temp->next = NULL;	
	}
}

void search(int roll){
	struct node* temp = head;
	int count=1,flag=0;
	while(temp!=NULL){
		if(temp->roll==roll){
			printf("POSITION at %d\n",count);
			printf("FOLLOWING DATA OF ROLL NO. :\n");	
			printf("ROLL NO. : %d\nNAME : %s\nCGPA : %f\n\n",temp->roll,temp->name,temp->cgpa);
			flag=1;			
			break;
		}
		++count;
		temp = temp->next;
	}
	if(flag==0)printf("NOT FOUND\n");
}

void DISPLAY(){
	struct node* temp = head;
	if(temp==NULL)printf("NOTHING TO DISPLAY\n");
	else{
		while(temp!=NULL){
			printf("ROLL NO: %d\nNAME: %s\nCGPA:%f\n\n",temp->roll,temp->name,temp->cgpa);
			temp=temp->next;
		}
	}
}

int main()
{
	head = NULL;
	while(1){	
		printf("1.INSERT : \n2.DELETE : \n3.SEARCH : \n4.DISPLAY : \n");
		int ch;
		scanf("%d",&ch);
		if (ch==1)
		{
			int ch1;
			printf("1.INSERT at BEGINNING: \n2.INSERT at END: \n3.INSERT at BETWEEN:\n");
			scanf("%d",&ch1);
			int roll;
			char name[100];
			float cgpa;
			printf("Enter UNIQUE ROLL NO. to be inserted\n");
			scanf("%d",&roll);
			printf("Enter NAME to be inserted\n");
			gets(name);
			printf("Enter CGPA to be inerted\n");
			scanf("%f",&cgpa);
			if (ch1==1)
			{
				ins_beg(roll,name,cgpa);
			}
			else if (ch1==2)
			{
				ins_end(roll,name,cgpa);
			}
			else if (ch1==3)
			{
				printf("Enter the POSITION where node is to be inserted\n");
				int k;
				scanf("%d",&k);
				ins_btw(roll,name,cgpa,k);
			}
			else printf("INVALID INPUT\n");
		}
		else if(ch==2){
			int ch1;
			printf("1.DELETE at BEGINNING: \n2.DELETE at END: \n3.DELETE at BETWEEN:\n");
			scanf("%d",&ch1);
			if(ch1==1){
				del_beg();
			}
			else if(ch1==2){
				del_end();
			}
			else if(ch1==3){
				printf("Enter the POSITION at which node is to be DELETED\n");
				int k;
				del_btw(scanf("%d",&k));		
			}
			else printf("INVALID POSITION");

		}
		else if(ch==3){
			int roll;
			printf("Enter UNIQUE ROLL NO. to be searched\n");
			scanf("%d",&roll);
			search(roll);
		}
		else if(ch==4)DISPLAY();
		else {printf("INVALID INPUT\n");break;}
	}
	return 0;
}
