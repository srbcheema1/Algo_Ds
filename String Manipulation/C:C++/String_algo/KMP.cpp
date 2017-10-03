/* 
   Time-Complexity :- O(length of string)
   Used for outputing indices where a particular text appears in a given string
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
#define ii pair<int,int>
#define MP make_pair
#define pb push_back
#define ll long long int
#define fill(v,d) memset(v,d,sizeof(v))
#define INF 1000000005
#define PI acos(-1.0)
vector<int> b;
string p,t;
int i;
void preprocess(string a)
{
  int i = 1,j = 0;
  b[0] = 0;
  while(i < (int)a.length())
  {
   while(j > 0 && a[i] != a[j])
   { j--;
     j= b[j];
   }
   if(a[i] == a[j])
    j++;
   b[i] = j;
   i++;
  }
}
void kmp(string a,string t)
{
  int i=0,j=0;
  while(i<(int)a.length())
  {
    while(j > 0 && a[i] != t[j])
    { j--;
      j= b[j];
    }
    if(a[i] == t[j])
     j++;
    if(j == (int)t.length())
    { cout<<i-j+1<<" ";
      j=b[t.length()-1];
    }
    i++;
  }
}
int main()
{  std::ios_base::sync_with_stdio(false); cin.tie(NULL);
   cin>>t>>p;
   b.resize(p.length());
   preprocess(p);
   loop(i,0,b.size())
    cout<<b[i]<<" ";
   cout<<endl;
   kmp(t,p);
   return 0;
}
