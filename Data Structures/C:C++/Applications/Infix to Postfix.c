#include<stdio.h>

int j;
struct temp{
	char a[200];
	int top;
};
struct temp s;

void push(char item){
	s.a[++s.top]=item;
}

int isempty(){
	return s.top==-1;
}

char pop(){
	if(!isempty())return s.a[s.top--];
}

int isoperator(char c){
	if(c=='*'||c=='/'|| c=='+'|| c=='-')return 1;
	return 0;
}
int precedence(char c){
	if(c=='+' || c=='-')return 1;
	else if(c=='*' || c=='/')return 2;
	else if(c=='^')return 3;
	return 0;
}
char *infix_postfix(char *p){
	int i;
	j=0;
	char *p1 = (char *)malloc(100*sizeof(char));
	for(i=0;p[i]!='\0';i++){
		//printf("%d\n",j);
		if(isalpha(p[i]) || isdigit(p[i])){
			p1[j++]=p[i];
		}
		else if(isoperator(p[i])){//printf("%c\n",p[i]);
			while(!isempty() && /*s.a[s.top]!='(' &&*/ (precedence(p[i]) <= precedence(s.a[s.top]))){
				p1[j++] = s.a[s.top];
				pop();
			}	
			push(p[i]);
		}
		else if(p[i]=='(')push(p[i]);
		else if(p[i]==')'){
			while(!isempty() && s.a[s.top]!='('){
				p1[j++]=s.a[s.top];
				pop();
			}
			pop();
		}
	}
	while(!isempty()){
		//printf("%c ",s.a[s.top]);
		p1[j++]=s.a[s.top];
		pop();
	}
	//for(i=0;i<j;i++)printf("%c",p[i]);
	return p1;
}

int main(){
	s.top = -1;
	char *p = (char *)malloc(100*sizeof(char));
	while(1){
		printf("Enter expression : \n");
		gets(p);
		char *p1 = infix_postfix(p);
		//infix_postfix(exp);
		int i;
		for(i=0;i<j;i++)printf("%c",p1[i]);
		printf("\n");
	}
	return 0;
}
