#include<stdio.h>

struct node{
	int item;
	struct node* next;
};

struct node* head;

struct node* reverse(){
	struct node* pre;
	struct node* current;
	struct node* post;
	current = head;
	pre = NULL;
	while(current!=NULL){
		post = current->next;
		current->next = pre;
		pre = current;
		current = post; 		
	}
	head = pre;
	return head;
}

void insert(int item,int n){
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->item = item;
	temp->next = NULL;
	if(n==1){
		temp->next = head;
		head = temp;
		return;
	}
	struct node* temp1;
	temp1 = head;
	int i;
	for( i = 0;i<n-2;i++){
		temp1 = temp1->next;
	}
	temp->next = temp1->next;
	temp1->next = temp;
}

void print(){
	struct node* temp = head;
	while(temp!=NULL){
		printf("%d ",temp->item);
		temp = temp->next;
	}
	printf("\n");
}

int main(){
	head = NULL;
	insert(8,1);
	insert(51,2);
	insert(21,3);
	print();
	reverse();
	print();
}
