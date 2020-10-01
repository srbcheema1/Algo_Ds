/*
	Created by :-Ashutosh Singh
	Date of Creation :- 06/08/2019
	An algorithm to find nth element of the fibonacci series starting with 0 and 1.
	Faster than matrix exponentiation for n upto 10^10.
 */
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007 
int a,b,c,d;
void fast_fibo(int n,int ar[])
{
	if(n==0)
	{
		ar[0]=0;
		ar[1]=1;
		return ;
	}
	fast_fibo(n/2,ar);
	a=ar[0];		//	f(n)
	b=ar[1];		//	f(n+1)
	c=2*b-a;	
	if(c<0)			//for dealing negative values of c.(c+mod)%mod is always > 0
		c+=mod;		//irrespective of negative c.
	c=(a*c)%mod;	//	f(2*n)=f(n)*(2*f(n+1)-f(n))
	d=(a*a+b*b)%mod; // f(2*n+1)=f(n)*f(n) + f(n+1)*f(n+1)
	if(n%2==0)
		{
			ar[0]=c;
			ar[1]=d;
		}
	else
	{
			ar[0]=d;
			ar[1]=c+d;
	}
	return;
} 
int main()
{
	int n;
	cin >> n;	// nth fibonacci value to be found
	int ar[2]={0};
	fast_fibo(n,ar);
	cout << "The " << n << "th fibonacci number is " << ar[0];
	return 0;
}
