#include<stdio.h>
int main(){
int x,y,z;
printf("Enter 1st number");
scanf("%d",&x);

printf("Enter 2nd number");
scanf("%d",&y);

printf("Enter 3rd number");
scanf("%d",&z);
int big=(x>y)?((x>z)?x:z):(y>z)?y:z;
printf("%d",big);
}
