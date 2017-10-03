#include<stdio.h>
int main(){
int x;
printf("Enter the number");
scanf("%d",&x);

int fact=1;

for(fact=1;x>1;x--){
fact=fact*x;
}
printf("%d",fact);
return 0;




}
