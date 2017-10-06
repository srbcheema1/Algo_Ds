//https://www.hackerrank.com/contests/university-codesprint-3/challenges/erupting-volcanoes
#include<bits/stdc++.h>

#define F0(i,t) for(int i=0; i<t; i++)
#define F1(i,t) for(int i=1; i<=t; i++)
#define Si(x) scanf("%d",&x)
#define Si2(x,y) scanf("%d %d",&x,&y)
#define Sl(x) scanf("%lld",&x)
#define Sl2(x,y) scanf("%lld %lld",&x,&y)
#define dout if(debugg)cout<<" "

   /* * * * * * * * * * * * * * * * * * * * * * * *
    *                                             *
    *            _/_/_/            _/             *
    *         _/        _/  _/_/  _/_/_/          *
    *          _/_/    _/_/      _/    _/         *
    *             _/  _/        _/    _/          *
    *      _/_/_/    _/        _/_/_/             * 
    *                                             *
    * * * * * * * * * * * * * * * * * * * * * * * */

using namespace std;

typedef unsigned long long int ulli;
typedef unsigned int ui;
typedef pair<int,int> mp;
typedef vector<vector<int> > matrix;

struct elem{
    int x;
    int y;
    int w;
    elem(int x,int y,int w){
        this->x = x;
        this->y = y;
        this->w = w;
    }
};

int debugg = 0;

void fill(int x,int y,int w,int n,matrix& mat,matrix& filled){

    queue<elem> q;
    q.push(elem(x,y,w));
        
    while(!q.empty()){
        elem temp = q.front();
        x = temp.x; y = temp.y; w = temp.w;
        q.pop();

        if(x<0 || y<0 || x>=n || y>=n || w<=0 )continue;
        if(filled[x][y]==1) continue;

        filled[x][y]=1;
        mat[x][y] += w;

        q.push(elem(x+1,y,w-1));
        q.push(elem(x,y+1,w-1));
        q.push(elem(x-1,y,w-1));
        q.push(elem(x,y-1,w-1));
        
        q.push(elem(x-1,y+1,w-1));
        q.push(elem(x-1,y-1,w-1));
        q.push(elem(x+1,y+1,w-1));
        q.push(elem(x+1,y-1,w-1));
    }
}

int main(){
	int t=1;
    ios_base::sync_with_stdio(0);cin.tie(0);
	while(t--){
        int n,m,x,y,w,maxx=0;
        cin>>n>>m;
        matrix mat(n,vector<int>(n,0));

        while(m--){
            cin>>x>>y>>w; 
            matrix filled(n,vector<int>(n,0));
            fill(x,y,w,n,mat,filled);
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j] >maxx){
                    maxx=mat[i][j];
                }
            }
        }
        cout<<maxx<<endl;
	}
}
// a code by srbcheema1
