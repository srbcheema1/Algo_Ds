/*
This program can be used to multiply 2 numbers grater than 10^5, usually a major hurdle in languages like C/C++
in competitive programming, using this as a template one can perform implementations like Factorials of 100 etc
*/

#include <iostream>
using namespace std;
int main()
	{
		ios_base::sync_with_stdio(false);
		int n1, n2;
		cin>>n1>>n2;
		int c = 0, ans[100000] = {0}, i = 0, basei = 0, temp = n2, dig = 0, tmp;
		while(n1)
		    {
		        if(n2)
		            {
		                c = ( (n1%10)*(n2%10) );
		                ans[i] += c;
		                if(ans[i]>9)
		                    {
		                        ans[i+1] += ans[i]/10;
		                        ans[i] = ans[i]%10;
		                    }
		                c /= 10;
		                n2 /= 10;
		                dig++;
		                i++;
		            }
                else
                    {
                        tmp = dig;
                        n2 = temp;
                        n1 /= 10;
                        i = ++basei;
                        c=0;
                        dig = basei;
                    }
		    }
        for(int k = tmp-1 ;k>=0;k--)
            cout<<ans[k];
		return 0;
}
