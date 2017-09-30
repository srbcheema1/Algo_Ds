#include<stdio.h>
int main(){
int x,y,z;
printf("Enter the number\n");
scanf("%d",&x);
y=x/2;
if(x%2==0 && x!=2){
printf("It is not a  prime\n");
}

else{
for(z=3;z<=y;z++)
{

if(x%z==0){
printf("it is not a prime number ");
}
else{
printf("it is a  prime");
break;
}

}





return 0;


}
