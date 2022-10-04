#include <stdio.h>
#include <stdlib.h>

int main(){
	int n,i,RQ[100],head,totalheadmovement=0;
	printf("Enter the number of requests: ");
	scanf("%d",&n);
	printf("Enter the request sequence: ");
	for(i=0;i<n;i++){
		scanf("%d",&RQ[i]);
	}
	printf("Enter initial head position: ");
	scanf("%d",&head);
	
	for(i=0;i<n;i++){
		totalheadmovement = totalheadmovement+abs(RQ[i]-head);
		head = RQ[i];
	}
	printf("Total head movement is %d",totalheadmovement);
	return 0;
}
