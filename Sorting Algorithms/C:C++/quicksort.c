#include<stdio.h>
#include<time.h>
#define max 500
void qsort(int [],int,int);
int partition(int [],int,int);
void main()
{
int a[max],i,n;
clock_t s,e;
clrscr();
printf("enter the value of n: ");
scanf("%d",&n);
printf("Enter the values: ");
for(i=0;i<n;i++)
scanf("%d%",&a[i]);
printf("\nThe array elements before\n");
for(i=0;i<n;i++)
printf("%d\t",a[i]);
s=clock();
delay(100);
qsort(a,0,n-1);
e=clock();
printf("\nElements of the array after sorting are:\n");
for(i=0;i<n;i++)
printf("%d\t",a[i]);
printf("\nTime taken:%f",(e-s)/CLK_TCK);
getch();
}
void qsort(int a[],int low, int  high)
{
int j;
if(low<high)
{
j=partition(a,low,high);
qsort(a,low,j-1);
qsort(a,j+1,high);
}
}
int partition(int a[],int low, int high)
{
int pivot,i,j,temp;
pivot=a[low];
i=low+1;
j=high;
while(i<j)
{
while(pivot>a[i] && i<=high)
i++;
while(pivot<a[j])
j--;
if(i<j)
{
temp=a[i];
a[i]=a[j];
a[j]=temp;
}
else
temp=a[j];
a[j]=a[low];
a[low]=temp;
return j;
}
}

