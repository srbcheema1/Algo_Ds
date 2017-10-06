//https://www.hackerrank.com/contests/gs-codesprint/challenges/buy-maximum-stock////i///////i/s
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
typedef pair<lli,lli> mp;

int debugg = 0;

bool sort_fxn(mp a,mp b){
    return a.second < b.second;
}

/*
 * return maximum number of elements we can buy...
 * we can buy max i elements at i day
 * vector a is 0 based
 * a[i] contains price of that elem
 * k = max amount to be spent
 */
ulli buyMaximumProducts(ulli n, ulli k, vector <ulli> a) {
    vector<mp > vec(n);
    for(int i=0;i<n;i++)
        vec[i]=mp(i+1,a[i]);
    sort(vec.begin(),vec.end(),sort_fxn);

    ulli amount = k;
    ulli bought = 0;
    ulli buy;
    for(int i=0;i<n;i++){
        buy = min(vec[i].first,amount/vec[i].second);
        bought += buy;
        amount -= buy*vec[i].second;
        if(vec[i].second > amount) break;
    }
    return bought;
}

int main() {
    ulli n,k;
    cin >> n;
    vector<ulli> arr(n);

    for(ulli i = 0; i < n; i++)
       cin >> arr[i];

    ulli k;
    cin >> k;

    ulli result = buyMaximumProducts(n, k, arr);
    cout << result << endl;
}
// a code by srbcheema1
