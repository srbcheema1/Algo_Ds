#include<stdio.h>
#define N 4

void display(int sol[N][N])
{
	int i,j;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
			printf("%d ",sol[i][j]);
		printf("\n");
	}
}


int issafe(int maze[N][N],int x,int y)
{
	if((x>=0 && x<4) && (y>=0 && y<3) && maze[x][y]==1)
		return 1;
	else
		return 0;
}

int solvemaze(int maze[N][N],int x,int y,int sol[N][N])
{
	if(x==N-1 && y==N-1)
	{
		sol[x][y]=1;
		return 1;
	}
	
		if(issafe(maze,x,y)==1)
		{
			sol[x][y]=1;
			
			if(solvemaze(maze,x+1,y,sol)==1)
				return 1;
			
			if(solvemaze(maze,x,y+1,sol)==1)
				return 1;
			
			sol[x][y]=0;
			return 0;
		}
	return 0;
}

void solve(int maze[N][N])
{
	int sol[N][N]={{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
	if(solvemaze(maze,0,0,sol)==0)
	{
		printf("No Solution possible\n");
	}
	else
	{
		display(sol);
	}
}
void main()
{
	int maze[N][N]={{1,0,0,0},{1,1,0,1},{0,1,0,0},{1,1,1,1}};
	solve(maze);
}
