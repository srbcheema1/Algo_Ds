//QUESTION LINK
//CODEFORCES EDU/BINARY SEARCH
//https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/G



********************CODE*******************
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool good(ll a[],ll n,ll k,ll x)
{
    ll slots=x*k,i;
    for(i=0;i<n;i++)
    {
        slots-=min(a[i],x);
    }
    //cout<<slots<<endl;
    if(slots<=0)
    return 1;
    return 0;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t=1;
    while(t--)
    {
      ll n,ans=0,i,k;
    //   string s,w;
    //   cin>>s>>w;
    //   n=s.length();
      cin>>k>>n;
      ll a[n];
      for(i=0;i<n;i++)
      cin>>a[i];
      ll l=0,r=50*pow(10ll,9ll),mid;
     // cout<<n<<" "<<m;
      while(l<=r)
      {   //cout<<l<<" "<<r<<" ";
          mid=(l+r)/2;
          //cout<<a[mid]<<endl;
          if(good(a,n,k,mid))
          {
              l=mid+1;
              ans=mid;
          }
          else
          {
              r=mid-1;
          }
          
      }
      //cout<<l<<" "<<r<<" ";
      cout<<ans<<" ";
      
   
    }
 
	return 0;
}
//TIME COMPLEXITY==>O(nlogn)
//SPACE COMPLEXITY==>O(1)
