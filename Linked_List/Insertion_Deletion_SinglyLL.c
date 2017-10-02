#include<stdio.h>

struct node{
	int item;
	struct node* next;
};

struct node* head;

void Insert(){
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	int x;
	printf("\nEnter element to be inserted : ");
	scanf("%d",&x);
	printf("\n");
	temp->item = x;
	temp->next = NULL;
	temp->next = head;
	head = temp;
}

void delete(){
	int x;
	if(head==NULL){
		printf("Nothing to be deleted\n");
		return;
	}
	printf("Enter the position to be deleted : ");
	scanf("%d",&x);printf("\n");
	if(head->next==NULL){//only a single element is present
		head=NULL;
		return;
	}	
	struct node* temp;
	temp = head;
	int i;
	for(i=0;i<x-2;i++){
		temp = temp->next;
	}//came to n-1th node
	temp = temp->next->next;
	temp->next = NULL;
}

void Print(){
	struct node* temp = head;
	while(temp!=NULL){
		printf("%d  ",temp->item);
		temp = temp->next;
	}
	printf("\n");
}

int main(){
	head = NULL;
	printf("Enter number of Items : ");
	int n;
	scanf("%d",&n);
	printf("\n");
	int i;
	for(i=0;i<n;i++){
		int ch;
		printf("What would you like to perform:");
		scanf("%d",&ch);
		if(ch==1){
				Insert();
		}
		else if(ch==3){
			Print();
		}
		else if(ch==2){
			delete();
		}	
	}
}
