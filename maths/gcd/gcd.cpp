#include<stdio.h>

/*
 * be careful a must not be zero
 * if so then ans is b
 */
int gcd(int a,int b){
    if(b%a==0)
        return a;
    return gcd(b%a,a);
}

int main()
{
	int t=1,a,b,ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&a,&b);
		if(a==0)//gcd throw exception on a = 0
	        ans = b;
	    else ans=gcd(a,b);
		printf("%d\n",ans);
	}
	return 0;
}
