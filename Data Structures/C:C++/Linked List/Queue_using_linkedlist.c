#include<stdio.h>

//insert at beginning and remove at the end

struct node{
	int item;
	struct node* next;
};

struct node* head;

void push(){//insert at the beginning
	struct node* ptr = (struct node*)malloc(sizeof(struct node));
	printf("Enter element to be inserted : ");
	scanf("%d",&ptr->item);
	ptr->next = NULL;
	if(head == NULL){
		head = ptr;
		return;
	}
	ptr->next = head;
	head = ptr; 	
}

void pop(){
	struct node* temp = head;
	if(head == NULL){
		printf("Nothing to Pop\n");
		return;
	}
	else if(head->next == NULL){
		head = NULL;
		return;
	}
	while(temp->next->next!=NULL){
		temp = temp->next;
	}	
	
	temp->next = NULL;
}

void display(){
	struct node* temp = head;
	if(temp==NULL){
		printf("Nothing to display\n");
	}
	while(temp!=NULL){
		printf("%d ",temp->item);
		temp = temp->next;
	}
	printf("\n");
}

int main(){
	head = NULL;
	while(1){
		printf("\n1.Push\n2.Pop\n3.Display\nAny other number to Exit\n\n");
		printf("Enter your choice : ");
		int ch;
		scanf("%d",&ch);
		printf("\n");
		if(ch==1){
			push();
		}
		else if(ch==2){
			pop();
		}
		else if(ch==3){
			display();
		}
		else{
			break;
		}
	}
}
