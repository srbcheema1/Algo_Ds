#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=(a);i<(b);i++)

void bfs(int n, std::vector<int> v[], int s){
	int c[n+1]={0};//colour of vertices
	//0 white 1 gray 
	c[s] = 1;
	queue<int> q;
	q.push(s);
	int t;
	while(!q.empty()){
		t = q.front();
		cout << t << " ";
		//q.front();
		q.pop();
		For(i,0,v[t].size()){
			if(c[v[t][i]] == 0){
				c[v[t][i]] = 1;
				q.push(v[t][i]);
			}
		}
	}

}

int main(){
	
	cout << "Enter number of vertices : ";
	int n; cin >> n;
	std::vector<int> v[n+1];
	cout << "Enter number of edges (Undirected Graph) : ";
	int e,a,b; cin >> e;
	cout << "Enter edges now : ";
	For(i,0,e){
		cout << "\nEdge no." << i+1 << " : ";
		cin >> a;
		cin >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	cout << "Find BFS from which vertex ? ";
	int s;cin >> s;
	bfs(n,v,s); 
}