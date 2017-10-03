/* 
   Time-Complexity :- O(nlog(n)^2),where n is the length of string
   Used for outputing all the suffixes in a sorted way
*/
#include<bits/stdc++.h>
#include<sstream>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
#define mod 1000000007
#define all(v) v.begin(),v.end()
#define loop(i,a,b) for(i=(int)a;i<(int)b;i++)
#define revloop(i,a,b) for(i=(int)a;i>=(int)b;i--)
#define stloop(it,v) for(it=v.begin();it!=v.end();++it)
#define ii pair<int,string>
#define MP make_pair
#define pb push_back
#define ll long long int
#define fill(v,d) memset(v,d,sizeof(v))
#define INF 1000000005
#define PI acos(-1.0)
vector<vector<int> > sa;
struct mytuple{
 int orig;
 int first;
 int second;
};
bool cmp(mytuple a,mytuple b)
{
  if(a.first == b.first)
    return a.second < b.second;
  return a.first < b.first;
}
int main()
{  std::ios_base::sync_with_stdio(false); cin.tie(NULL);
   string a;
   int i,n,curr,cnt,stp;
   cin>>a;
   n = a.length();
   stp = log(n)/log(2) + 2;
   sa.assign(stp,vector<int>(n));
   loop(i,0,n)
    sa[0][i] = a[i]-'a';
   mytuple L[n];
   stp = 1;
   for(cnt = 1;cnt < n; cnt*=2)
   {
     for(i=0;i<n;i++)
     {
      L[i].first = sa[stp-1][i];
      L[i].orig=i;
      if(i+cnt<n)
       L[i].second = sa[stp-1][i+cnt];
      else
       L[i].second = -1;
     }
     sort(L,L+n,cmp);
     sa[stp][L[0].orig] = curr = 0;
     for(i=1;i<n;i++)
     {
       if((L[i].first != L[i-1].first) || (L[i].second != L[i-1].second))
        curr++;
       sa[stp][L[i].orig] = curr;
     }
     stp++;
   }
   loop(i,0,n)
   { stp = L[i].orig;
     cout<<stp<<" "<<a.substr(stp,n-stp)<<endl;
   }
   return 0;
}
