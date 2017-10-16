/*Stack Using LinkedList
 * push O(1)
 * pop  O(1)
 */


#include<iostream>


using namespace std;

struct node{
	int item;
	node* next;
};


class stack{
	private:
		node* tos;
	public:
		stack(){
			tos=NULL;
		};
		void push(int);
		int pop();
		int top();
		int isEmpty();
};



void stack::push(int data){
	node *temp=new node();
	temp->item=data;
	if(tos==NULL){
		tos=temp;
		temp->next=NULL;
		return;
	}
	else{
		temp->next=tos;
		tos=temp;
	}
}


int stack::pop(){
	node *temp=tos;
	int data;
	if(tos==nullptr){
		cout<<"UNDERFLOW"<<endl;
		exit(0);
	}
	else{
		data=temp->item;
		tos=temp->next;
		free(temp);
		return data;
	}
}


int stack::isEmpty(){
	return tos==nullptr;
}

int stack::top(){
	if(tos==NULL){
		cout<<"EMPTY"<<endl;
		return -1;
	}
	return tos->item;
};

		
int main(){
	int choice,temp,x;
	stack s;
	do{
		cout<<"1:PUSH \t 2:POP \t 3:TOP \t 4:isEmpty \n";
		cin>>choice;
		switch(choice){
			case 1:
				cout<<"ENTER VALUE :";
				cin>>temp;
				s.push(temp);
				break;
			case 2:
				cout<<"POPPED ELEMENT IS "<<s.pop()<<endl;
				break;
			case 3:
				cout<<"TOP = "<<s.top();
				break;
			case 4:
				if(!s.isEmpty())
					cout<<"NOT EMPTY"<<endl;
				else
					cout<<"EMPTY"<<endl;
				break;
		}
		cout<<"Continue (1/0): ";
		cin>>x;
	}while(x!=0);
	return 0;
}
