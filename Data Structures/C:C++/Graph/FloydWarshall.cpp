//Floyd Warshall Algorithm for All Pair Shortest Path Problem
#include <bits/stdc++.h>
#define FOR(i,n) for(size_t i=0;i<n;++i)
#define endl '\n'
#define ll long long
#define pb push_back
#define mp make_pair
using namespace std;

ll gcd(ll a , ll b){return a==0?b:gcd(b%a,a);}

int main(){
	//Floyd Warshall algorithm for all pair shortest path algorithm
	//NOTE - Vertices in this are from 0 to V-1. For 1 to V, modify the code!!
	//Complexity is O(V*V*V). Thi
	int e,v,a,b,weight, floyd_warshall [1000][1000],i,j,k,temp;
	cin>>v>>e;
	FOR(i,v){
		FOR(j,v)
		{
			if(i!=j)
				floyd_warshall[i][j] = 99999999;
			else floyd_warshall[i][j] = 0;
		}
	}

	FOR(i,e){
		cin>>a>>b>>weight;
		floyd_warshall[a][b] = weight;
	}
	
	FOR(k,v){
		FOR(i,v){
			FOR(j,v){
				temp = floyd_warshall[i][k] + floyd_warshall[k][j];
				if(temp <  floyd_warshall[i][j])
					floyd_warshall[i][j] = temp;
			}
		}
	}
	cout<<floyd_warshall[2][3];
	return 0;
}
