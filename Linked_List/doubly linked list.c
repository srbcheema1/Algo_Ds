#include<stdio.h>

struct node{
	int item;
	struct node* pre;
	struct node* next;
};

struct node *head, *ptr;

struct node* getNode(){
	ptr = (struct node*)malloc(sizeof(struct node));
	printf("Enter element to be inserted in Doubly Linked List : ");
	int x;
	scanf("%d",&x);
	ptr->item = x;
	ptr->pre = NULL;
	ptr->next = NULL;
	return ptr;
}

void insert(){
	struct node* ptr = getNode();
	ptr->next = head;
	if(head == NULL){
		head = ptr;
		return;
	}	
	head->pre = ptr;
	head = ptr;
}

void insert1(){
	struct node* ptr = getNode();
	if(head==NULL){
		head = ptr;
		return;
	}
	struct node* temp;
	temp=head;
	while(temp->next!=NULL){
		temp = temp->next;
	}//temp is last element
	
	temp->next = ptr;
	ptr->pre = temp;
	ptr->next = NULL;		
}


void print(){
	struct node* temp;
	temp = head;
	while(temp!=NULL){
		printf("%d ",temp->item);
		temp = temp->next;
	}
}

int main(){
	head = NULL;
	insert();//insert inserts at beginning
	insert();
	insert1();//insert1 inserts at end
	insert1();
	print();
}
