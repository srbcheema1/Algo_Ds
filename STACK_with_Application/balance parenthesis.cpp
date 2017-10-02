#include<iostream>
#include<bits/stdc++.h>
#include<string.h>
#include<stack>
using namespace std;

int main(){
	string str;
	printf("Enter a String");
	cin>>str;
	int l = str.length();
	stack <char> s;
	for(int i=0;i<l;i++){
		if(str[i]=='{' || str[i]=='[' || str[i]=='('){
			s.push(str[i]);
		}
		else if(str[i]=='}' || str[i]==']' || str[i]==')'){
			if(s.empty()){
				printf("\nNot Balanced\n");
				return false;
			}
			else{
				if(str[i]=='}' && s.top()=='{'){
					s.pop();
				}
				else if(str[i]==']' && s.top()=='['){
					s.pop();
				}
				else if(str[i]=='(' && s.top()==')'){
					s.pop();
				}
				else{
					printf("\nNot Balanced\n");return false;
				}
			}
		}
	}
	if(s.empty()){
		printf("\nBalanced\n");
	}
	else{
		printf("\nNot Balanced\n");
	}
}
