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

int debugg = 0;

int two_pow(int p){
    int ans = 1,fact =2;
    while(p){
        if( p&1 )//p is odd
            ans = ans * fact;
        fact = fact * fact;
        p = p>>1;
    } 
    return ans;
}

int main(){
	int t=1;
    ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>t;
	while(t--){
        int p;
        cin>>p;
        cout<<two_pow(p)<<endl;
	}
}
// a code by srbcheema1
