//Auhor : VIVEK SHAH
/*Performs Push, Pop, Peep and Displays elements of Stack*/


#include<stdio.h>

struct stack{
	char book_name[200][200];
	int book_id[20];
	int book_price[20];
	int top;
};

struct stack *p;
int size;

void push(){
	if((p->top)==size-1){
		printf("Overflow");
		return;
	}
	p->top = p->top +1;
	//printf("p->top = %d",p->top);
	printf("\nEnter elements to be pushed : ");
	printf("\nEnter book name:");
	scanf("%s",p->book_name[p->top]);
	printf("\nEnter book id:");
	scanf("%d",&p->book_id[p->top]);
	printf("\nEnter book price:");
	scanf("%d",&p->book_price[p->top]);
}

void pop(){
	if(p->top==-1){
		printf("Underflow\n");
	}
	else{
		p->top = p->top - 1;
	}
}

void peep(){
	int i= p->top;
		printf("\nBook Name : %s",p->book_name[i]);
		printf("\nBook ID : %d",p->book_id[i]);
		printf("\nBook Price : %d",p->book_price[i]);
		printf("\n");
}

void print(){
	int x = p->top;
	if(x==-1){
		printf("Nothing to be displayed\n");
	}
	int i;
	for(i=0;i<=x;i++){
		printf("\nBook Name : %s",p->book_name[i]);
		printf("\nBook ID : %d",p->book_id[i]);
		printf("\nBook Price : %d",p->book_price[i]);
		printf("\n");
	}	
}

int main(){
	printf("********************************\t\n");
	printf("Enter stack size : ");
	scanf("%d",&size);
	p = (struct stack*)malloc(sizeof(struct stack));
	p->top = -1;
	while(1){
		printf("\n1.Push\n2.Pop\n3.Peep\n4.Display all elements\n5.Exit\n");
		int ch;
		scanf("%d",&ch);
		if(ch==1){
			//p->top = p->top + 1;
			push();
		}
		else if(ch==2){
			pop();
		}
		else if(ch==3){
			peep();
		}
		else if(ch==4){
			print();
		}
		else{
			break;
		}
	}
}
