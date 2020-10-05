#include <bits/stdc++.h>
using namespace std;

int main(){

	int n;
	cin >> n;

	int count = 1;
	//int k=0;
    int a[n+1][2*n-1+1];
    memset(a,0,sizeof(a));//filling complete area by spaces.
	char spaces = ' ';
	   for(int i=1;i<=n;i++)
		{int x=n-(i-1);
		 for( int j = 1; j <= i; j++ ){
			 a[i][x]=count;
			  count++;
			 x+=2;	
		}
	   }
	
	        
		for(int i=1;i<=n;i++)
		{
			for( int j =1; j <=2*n-1;j++){
				if (a[i][j]==0)
					cout<<spaces;
				else
			                cout<<a[i][j];
		}
		cout<<endl;
			
	        }
	       

    return 0;

}

/*
4 


     1
    2 3
   4 5 6
 7 8 9 10

*/

