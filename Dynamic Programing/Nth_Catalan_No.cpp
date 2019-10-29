#include <iostream>
using namespace std;
int main() {
	    int n;
	    cout<<"enter value of n\n";
	    cin>>n;
	   unsigned long int cat[n+1];
	    cat[0]=1;
	    for(int i=1;i<=n;i++){
	        cat[i]=((2*i-1)*cat[i-1]*2)/(i+1);	       
	    }
	    cout<<cat[n]<<"\n";	
	return 0;
}
