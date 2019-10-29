#include <iostream>
using namespace std;
#include<string.h>
#include<limits.h>
int main() {
	string x,y;
	int len1,len2;
	getline(cin,x);
	getline(cin,y);
	len1=x.length();
	len2=y.length();
	int arr[len1+1][len2+2];
	for(int i=0;i<=len1;i++){
	    for(int j=0;j<=len2;j++){
	        arr[i][j]=0;
	    }
	}
	int max=0;
	for(int i=1;i<=len1;i++){
	    for(int j=1;j<=len2;j++){
	        if(x[i-1]==y[j-1])
	          { arr[i][j]=arr[i-1][j-1]+1;
	          if(arr[i][j]>max)
	           max=arr[i][j];
	          }
	    }
	}

	cout<<max<<"\n";
	return 0;
}
