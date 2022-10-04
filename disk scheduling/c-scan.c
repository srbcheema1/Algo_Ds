#include <stdio.h>
#include <stdlib.h>

int main(){
	int n,i,j,index,temp,RQ[100],head,totalheadmovement=0,size,move;
	printf("Enter the number of requests: ");
	scanf("%d",&n);
	printf("Enter the request sequence: ");
	for(i=0;i<n;i++){
		scanf("%d",&RQ[i]);
	}
	printf("Enter initial head position: ");
	scanf("%d",&head);
	
	// size is the no of tracks
	printf("Enter the total disk: ");
	scanf("%d",&size);
	
	printf("Enter the head movement (1-high ; 0-low): ");
	scanf("%d",&move);
	
	// bubble sort
	for(i=0;i<n;i++){
		for(j=0;j<n-i-1;j++){
			if(RQ[j]>RQ[j+1]){
				temp = RQ[j];
				RQ[j] = RQ[j+1];
				RQ[j+1] = temp;
			}
		}
	}
	
	// Fetching the index
	for(i=0;i<n;i++){
		if(head < RQ[i]){
			index=i;
			break;
		}
	}
	
	// Condtn. for high 
	if(move==1){
		for(i=index;i<n;i++){
			totalheadmovement = totalheadmovement+abs(RQ[i]-head);
			head = RQ[i];
		}
		
		totalheadmovement = totalheadmovement + abs(size-RQ[i-1]-1);
		totalheadmovement = totalheadmovement + abs(size-1-0);
		head = 0;
		
		for(i=0;i<index;i++){
			totalheadmovement = totalheadmovement+abs(RQ[i]-head);
			head = RQ[i];
		}
	}
	// Condtn. for low
	else{
		for(i=index-1;i>=0;i--){
			totalheadmovement = totalheadmovement+abs(RQ[i]-head);
			head = RQ[i];
		}
		
		totalheadmovement = totalheadmovement + abs(RQ[i+1]-0);
		head = size-1;
		
		for(i=n-1;i>=index;i--){
			totalheadmovement = totalheadmovement+abs(RQ[i]-head);
			head = RQ[i];
		}
	}
	
	printf("Total head movement is %d",totalheadmovement);
	return 0;
}


