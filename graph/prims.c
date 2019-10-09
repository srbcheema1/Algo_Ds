#include<stdio.h>
#include<conio.h>
void main()
{
	int cost[20][20],t[20][20],near1[20],a[20];
	int i,j,n,min,minimum,k,l,mincost,c,b;
	clrscr();
	printf("\n Enter the number of nodes\n");
	scanf("%d",&n);
       /*	cost[i][j]=rand()%100;    */

       printf("\n Enter the Adjacency Matrix\n");
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			scanf("%d",&cost[i][j]);
	minimum=cost[1][1];
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		{
			if(minimum>=cost[i][j])
			{
				minimum=cost[i][j];
				k=i;
				l=j;
			}
		}
	mincost=minimum;
	t[1][1]=k;
	t[1][2]=l;
	for(i=1;i<=n;i++)
	{
		if(cost[i][l]<cost[i][k])
			near1[i]=l;
		else
			near1[i]=k;
	}
	near1[k]=near1[l]=0;
	for(i=2;i<=n-1;i++)
	{
		min=999;
		for(j=1;j<=n;j++)
		{
			if(near1[j]!=0)
			{
				a[j]=cost[j][near1[j]];
				{
					min=a[j];
					c=near1[j];
					b=j;
				}
			}
		}
		mincost=mincost+cost[b][c];
		near1[b]=0;
		for(k=1;k<=n;k++)
			if((near1[k]!=0)&&(cost[k][near1[k]]>cost[k][b]))
				near1[k]=b;
	}
	printf("\n The Cost of Minimum Spanning Tree is=%d",mincost);
	getch();
}

