#include<stdio.h>

struct node{
	int item;
	struct node* next;
};

struct node* head;
int size;

void insertathead(){
	struct node* ptr;
	ptr = (struct node*)malloc(sizeof(struct node));
	printf("Enter data : ");
	scanf("%d",&ptr->item);
	printf("\n");
	ptr->next = head;
	head = ptr;
}

void pop(){
	if(head==NULL){
		printf("UnderFlow\n");
		return;
	}/*
	if(head->next == NULL){
		head=NULL;
		return;
	}
	struct node* temp;
	temp = head;*/
	head = head->next;
	//temp->next = NULL;
}
void print(){
	struct node* temp;
	temp = head;
	printf("List : ");
	while(temp!=NULL){
		printf("%d ",temp->item);
		temp = temp->next;
	}
	printf("\n");
}

int main(){
	head=NULL;
	printf("Enter the size of array\n");
	scanf("%d",&size);
	while(1){
		printf("Enter choice\n1.Insert\n2.Pop\n3.Print\n");
		int ch;
		scanf("%d",&ch);
		if(ch==1){
		insertathead();
		}
		else if(ch==2){
			pop();	
		}
		else if(ch==3){
			print();
		}
	}
}
