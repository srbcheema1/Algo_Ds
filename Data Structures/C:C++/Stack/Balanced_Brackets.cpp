/*This program checks whether an entered string is Bracket Balanced ot not.By Bracket balanced we mean a opening bracket ('(','{','[') to be complemented by a closing bracket (')','}',']').
Time Complexity :O(n)
Auxiliary Space :O(n)
Similar quesion(s) for practice :https://www.hackerrank.com/challenges/balanced-brackets/problem
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	string str;
	getline(cin,str);
    stack<char> s;
    
    char a,b,c;
    int flag=1;

	for(int i=0;i<str.length();i++)
	{
		if (str[i]=='('||str[i]=='['||str[i]=='{')
        {
            // Push the element in the stack
            s.push(str[i]);
        }
        else
        {
            switch (str[i])
            {
            case ')':
 
                // Store the top element in a
                a = s.top();
                s.pop();
                if (a=='{'||a=='[')
                {
                  
                    flag=0;
                }
                break;
            case '}':
 
                // Store the top element in b
                b = s.top();
                s.pop();
                if (b=='('||b=='[')
                {
                   
                    flag=0;
                }
                break;
            case ']':
 
                // Store the top element in c
                c=s.top();
                s.pop();
                if (c=='('||c=='{')
                {
                
                    flag=0;
                }
                break;
            }
        }
	}
    if (s.empty() && flag==1)
        cout<<"Balanced";
    else
        cout<<"Unbalanced";
}
	

