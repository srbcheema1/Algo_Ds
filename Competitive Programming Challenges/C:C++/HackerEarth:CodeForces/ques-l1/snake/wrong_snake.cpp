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

void movehu(matrix& mat,int x,int y,int num,int n){
    if(y==0)
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<n;j++){
            mat[i][j]=num;
            num++;
        }
        i--;
        if(i<0)break;
        for(int j=n-1;j>=0;j--){
            mat[i][j]=num;
            num++;
        }
    }
    else
    for(int i=n-1;i>=0;i--){
        for(int j=n-1;j>=0;j--){
            mat[i][j]=num;
            num++;
        }
        i--;
        if(i<0)break;
        for(int j=0;j<n;j++){
            mat[i][j]=num;
            num++;
        }
    }
}
void movehd(matrix& mat,int x,int y,int num,int n){
    if(y==0)
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            mat[i][j]=num;
            num++;
        }
        i++;
        if(i>=n)break;
        for(int j=n-1;j>=0;j--){
            mat[i][j]=num;
            num++;
        }
    }
    else
    for(int i=0;i<n;i++){
        for(int j=n-1;j>=0;j--){
            mat[i][j]=num;
            num++;
        }
        i++;
        if(i>=n)break;
        for(int j=0;j<n;j++){
            mat[i][j]=num;
            num++;
        }
    }
}
void movevl(matrix& mat,int x,int y,int num,int n){
    if(x==0)
    for(int j=n-1;j>=0;j--){
        for(int i=0;i<n;i++){
            mat[i][j]=num;
            num++;
        }
        j--;
        if(j<0)break;
        for(int i=n-1;i>=0;i--){
            mat[i][j]=num;
            num++;
        }
    }
    else
    for(int j=n-1;j>=0;j--){
        for(int i=n-1;i>=0;i--){
            mat[i][j]=num;
            num++;
        }
        j--;
        if(j<0)break;
        for(int i=0;i<n;i++){
            mat[i][j]=num;
            num++;
        }
    }
}
void movevr(matrix& mat,int x,int y,int num,int n){
    if(x==0)
    for(int j=0;j<n;j++){
        for(int i=0;i<n;i++){
            mat[i][j]=num;
            num++;
        }
        j++;
        if(j>=n)break;
        for(int i=n-1;i>=0;i--){
            mat[i][j]=num;
            num++;
        }
    }
    else
    for(int j=0;j<n;j++){
        for(int i=n-1;i>=0;i--){
            mat[i][j]=num;
            num++;
        }
        j++;
        if(j>=n)break;
        for(int i=0;i<n;i++){
            mat[i][j]=num;
            num++;
        }
    }
}


void fill(matrix& mat,int x,int y,int d,int n){ 
    if(d==1 || d==2){//n  or s  ... move horizontally
        if(x==n-1){//horizontally up
            movehu(mat,x,y,1,n) ;
        }
        else{//horizontally down
            movehd(mat,x,y,1,n) ;
        }
    }
    else{//e or w ... move vertically
        if(y==n-1){//vertically left
            movevl(mat,x,y,1,n) ; 
        } 
        else{//vertically right
            movevr(mat,x,y,1,n) ;
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
