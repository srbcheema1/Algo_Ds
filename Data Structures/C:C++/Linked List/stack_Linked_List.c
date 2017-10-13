/*Implementation of stack using linked list */

/*Stack is a LIFO (Last In Fast Out Data Structure */

/*
 * push operation 	O(1)
 * pop operation	O(1)
 * top operation	O(1)
 * isEmpty operation 	O(1)
*/

#include <stdio.h>
#include <stdlib.h>
struct node{
	int item;
	struct node* next;
};

struct stack{
	struct node *tos;
};

typedef struct node node;
typedef struct stack stack;

/*Function to create stack*/
stack* createStack(){
	stack *temp=(stack*)malloc(sizeof(stack));
	temp->tos=NULL;
	return temp;
}


/*Function to push in a stack */
void push(stack *s,int data){
	node *temp=(node*)malloc(sizeof(node));
	/*checking if the memory was allocated to temp*/
	if(temp==NULL){
		printf("OVERFLOW\n");
		exit(0);
	}
	temp->item=data;
	if(s->tos==NULL){
		s->tos=temp;
		temp->next=NULL;
		return;
	}
	else{
		temp->next=s->tos;
		s->tos=temp;
		return;
	}
}

/*Function to pop an element from a stack */
int pop(stack *s){
	node *temp;
	int valueToReturn;
	if(s->tos==NULL){
		printf("UNDERFLOW\n");
		exit(0);
	}
	else{
		temp=s->tos;
		s->tos=temp->next;
		valueToReturn=temp->item;
		free(temp);
		return valueToReturn;
	}
}

/*function to check wheather the stack is empty */
int isEmpty(stack *s){
	return s->tos==NULL;
}


/*Functiont that returns the top of the stack */
int top(stack *s){
	if(!isEmpty(s))
		return s->tos->item;
	else
		return -1;
}



int main(){
	stack *s=createStack();
	int temp,ch,cont;
	do{
		printf("Enter choice\t1.Push\t2.Pop\t3.top :");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("Enter value :");
				scanf("%d",&temp);
				push(s,temp);
				break;
			case 2:
				printf("%d popped \n",pop(s));
				break;
			case 3:
				printf("top : %d\n",top(s));
				break;
		}
		printf("\nContinue (1/0)\n");
		scanf("%d",&cont);
	}while(cont != 0);
return 0;
}
