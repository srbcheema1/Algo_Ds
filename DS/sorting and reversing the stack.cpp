#include<iostream>
using namespace std;
void sort();
void push(string a);
class stack
{
	public:
	string a;
	stack*next;
};
stack*top=NULL;
stack*t=NULL;
void push(string data)
{
	stack *newnode=new stack;
	newnode->a=data;
	newnode->next=NULL;
	if(top==NULL)
	top=newnode;
	else
	{
		newnode->next=top;
		top=newnode;
	}
}
void sort()
{
	
	stack*i;
	stack*j;
	for(i=top;i!=NULL;i=i->next)
	{
		for(j=i->next;j!=NULL;j=j->next)
		{
			if(i->a<j->a)
			{
			swap(i->a,j->a);
            }
		}
	}
}
void display()
{
	stack*te=top;
	while(te!=NULL)
	{
		cout<<te->a<<" ";
		te=te->next;
	}
}
void reverse()
{
	stack *i;
	for(i=top;i!=NULL;i=i->next)
	{
	stack*node=new stack;
	node->a=i->a;
	node->next=NULL;
	if(t==NULL)
	{
	t=node;
    }
	else
	{		
            node->next=t;
			t=node;
	}
}
cout<<"\n";
while(t!=NULL)
{
	cout<<t->a<<" ";
	t=t->next;
}
}
int main()
{
	push("B");
	push("N");
	push("D");
	push("P");
	push("Z");
	push("Y");
	push("X");
	sort();
	display();
	reverse();
	return 0;
}



