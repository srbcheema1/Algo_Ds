#include <stdio.h>
#include <string.h>
#define MAX 200

int isoperator(char c){
	return (c=='*' || c=='/' || c=='+' || c=='-');
}

struct stack
{
	int top;
	double a[MAX];
}s;

void push(double c){
	s.a[++s.top]=c;
}

double pop(){
	return s.a[s.top--];
}

double perform(double a, double b, char c){
	if (c=='*')
	{
		return a*b;
	}
	else if (c=='+')
	{
		return a+b;
	}
	else if (c=='/')
	{
		return a/b;
	}
	else return a-b;
}

void post_infix(char a[],int l){
	int i;
	for(i=0;i<l;i++){
		if (isoperator(a[i]))
		{
			double sec = pop(); 
			//printf("%f",sec);
			double fir = pop(); 
			//printf("%f",fir);
			double res = perform(fir,sec,a[i]); 
			//printf("%f",res);
			push(res);
		}
		else{
			push(a[i]-'0');
		}
	}
}

int main()
{
	printf("Enter a postfix expression :\n");
	char post[100];
	s.top=-1;
	scanf("%s",post);
	int n=strlen(post);
	post_infix(post,n);
	printf("%f",s.a[s.top]);
	return 0;
}
