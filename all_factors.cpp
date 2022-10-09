#include <bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long ll;
typedef unsigned long int ull;

int main()
{
    ll n = 1e5 + 10;
    vector<ll> v[n];
    v[0].pb(0);
    v[1].pb(1);

    for (ll i = 2; i < n; i++)
    {
        for (ll j = i; j < n; j += i)
        {
            v[j].pb(i);
        }
    }

    int num;
    cin>>num;

    for(ll i=0; i<v[num].size(); i++)
    {
        cout<<v[num][i]<<" ";
    }
}