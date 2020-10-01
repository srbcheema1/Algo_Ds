#include<bits/stdc++.h>
using namespace std;
vector<int> v[1000];
int visited[1000];
int tin[1000],low[1000],t=0;
void initialise()
{
	for(int i=1;i<1000;i++)
		visited[i]=0;
}
void is_articulation_pt(int x)
{
	cout << x << " is an articulation point.\n";
}
void dfs(int x,int p=-1)
{
	visited[x]=1;
	tin[x]=low[x]=t++;
	int child=0;
	for(int i:v[x])
	{
		if(i==p)
			continue;
		if(visited[i])
			low[x]=min(low[x],tin[i]);
		else
		{
			dfs(i,x);
			low[x]=min(low[x],low[i]);
			if(low[i]>=tin[x] && p!=-1)
				{
					is_articulation_pt(x);
				}
			child++;
		}
	}
	if(p==-1 && child > 1)
	{
		is_articulation_pt(x);
	}
}
int main()
{
	int n,m;
	cout << "Enter number of vertices and edges.\n";
	cin >> n >> m;
	initialise();
	for(int i=0;i<m;i++)
		{
			int x,y;
			cin >> x >> y;
			v[x].push_back(y);
			v[y].push_back(x);			
		}
	for(int i=1;i<=n;i++)
	{
		if(!visited[i])
			dfs(i);
	}
	return 0;
}
