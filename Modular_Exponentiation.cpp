#include<bits/stdc++.h>
typedef long long ll;
#define mod 1000000007
using namespace std;
ll power(ll a,ll b,ll MOD = mod)
    {
        ll res = 1;
     
        while(b)
        {
            if(b & 1)
                res = ((__int128)res * a) % MOD;
            a = ((__int128)a * a) % MOD;
     
            b >>= 1;
        }
     
        return res;
    }
int main()
{
  ll x,y,t;
  cin >> x >> y;
  t=1000000007;
  ll z=power(x,y,t);
  cout << z%t ;
  return 0;
}
