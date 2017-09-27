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

struct Res_gcd{
    int gcd,x,y;
    Res_gcd(int gcd, int x, int y){
        this -> gcd = gcd;
        this -> x   = x;
        this -> y   = y;
    }
};
/*
 * return object of Res_gcd
 * Res_gcd.gcd ==> gcd of a,b
 * Res_gcd.x and Res_gcd.y ==> x and y such that ax + by = gcd(a,b)
 * NOTE : a must not be 0 ==> if so ans is b,0,1 
 */
Res_gcd gcd_extended(int a,int b){
    if(b%a==0)
        return Res_gcd(a,1,0);    //coz 1*a + 0*b = a { == gcd(a,b)}

    Res_gcd temp = gcd_extended(b%a,a);
    return Res_gcd( temp.gcd , temp.y - (b/a)*temp.x , temp.x );
}

int main(){
	int t=1;
    ios_base::sync_with_stdio(0);cin.tie(0);
    Res_gcd ans(1,1,1);
	cin>>t;
	while(t--){
        int a,b;
        cin>>a>>b;
        if(a==0)//fxn throw divide by 0 exception on a = 0
            ans = Res_gcd(b,0,1);
        else
            ans = gcd_extended(a,b);
        cout<<ans.gcd<<" "<<ans.x<<" "<<ans.y<<endl;
	}
}
// a code by srbcheema1
