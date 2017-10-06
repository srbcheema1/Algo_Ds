//https://www.hackerrank.com/contests/university-codesprint-3/challenges/the-snake-vs-the-wind
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

int debugg = 0;

void fill(matrix& mat,int x,int y,int d,int n){
    int num=1;
    if(d==1){//^
        while(true){
            mat[x][y]=num;
            num++;
            if(x-1>=0 && mat[x-1][y]==0){
                x = x-1;
            }
            else if(y-1>=0 && mat[x][y-1]==0){
                y=y-1;
            }
            else if(y+1<n && mat[x][y+1]==0){
                y=y+1;
            }
            else if(x+1<n && mat[x+1][y]==0){
                x=x+1; 
            }
            else{
                break;
            }
        } 
    }
    if(d==2){//v
        while(true){
            mat[x][y]=num;
            num++;
            if(x+1<n && mat[x+1][y]==0){
                x = x+1;
            }
            else if(y-1>=0 && mat[x][y-1]==0){
                y=y-1;
            }
            else if(y+1<n && mat[x][y+1]==0){
                y=y+1;
            }
            else if(x-1>=0 && mat[x-1][y]==0){
                x=x-1; 
            }
            else{
                break;
            }
        }
    }
    if(d==3){//>
        while(true){
            mat[x][y]=num;
            num++;
            if(y+1<n && mat[x][y+1]==0){
                y=y+1;
            }
            else if(x-1>=0 && mat[x-1][y]==0){
                x = x-1;
            }
            else if(x+1<n && mat[x+1][y]==0){
                x=x+1; 
            }
            else if(y-1>=0 && mat[x][y-1]==0){
                y=y-1;
            }
            else{
                break;
            }
        }
    }
    if(d==4){//<
        while(true){
            mat[x][y]=num;
            num++;
            if(y-1>=0 && mat[x][y-1]==0){
                y=y-1;
            }
            else if(x-1>=0 && mat[x-1][y]==0){
                x = x-1;
            }
            else if(x+1<n && mat[x+1][y]==0){
                x=x+1; 
            }
            else if(y+1<n && mat[x][y+1]==0){
                y=y+1;
            }
            else{
                break;
            }
        }
    }
}

int main(){
	int t=1;
    ios_base::sync_with_stdio(0);cin.tie(0);
	while(t--){
        int n,x,y,d;
        cin>>n;
        string dir;
        cin>>dir>>x>>y;
        
        if(dir[0]=='n')d=1;//^
        if(dir[0]=='s')d=2;//v
        if(dir[0]=='e')d=3;//>
        if(dir[0]=='w')d=4;//<
        
        matrix mat(n,vector<int>(n,0));
        fill(mat,x,y,d,n);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                cout<<mat[i][j]<<" ";
            cout<<endl;
        }
	}
}
// a code by srbcheema1
