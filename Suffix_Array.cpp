/*
Coded by :- Ashutosh Singh
Indian Institute of Information Technology Sricity
*/
#include <bits/stdc++.h>
// #include<boost/multiprecision/cpp_int.hpp>
// using namespace boost::multiprecision;
using namespace std;
#define ll long long
#define mod 1000000007
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define f(i, n) for (lli = 0; i < n; i++)
#define fp(i, k, n) for (lli = k; i <= n; i++)
#define fr(i, k, n) for (lli = k; i >= n; i--)
#define pb push_back

char str[50005];
int s[50005];
ll l;
int cmp(const void *a,const void *b) {
	return (strcmp((str+ *((int*)a)),(str+ *((int*)b))));
}

void suffix_array(int n) {
	int i;
	for(i=0;i<n;i++) s[i]=i;
	qsort(s,n,sizeof(int),cmp);
}
long long lcp() {
	int i, j;
	long long count = 0;
	char *z = str, *y = str;
	int p[50005] = {0};
	for(i=1;i<l;i++) {
    int cnt=0;
		z = str + s[i];
		y = str + s[i-1];
		while(*z==*y) {
			cnt++;
			z++;
			y++;
		}
		count += cnt;
	}
	return count;
}
void solve()
{
  scanf("%s",str);
  l = strlen(str);
  suffix_array(l);
  ll c = lcp();
  printf("%lld\n", (l*(l+1)/2)-c);
  return ;
}
int main()
{
  //FAST;
  ll T=1;
  cin >> T;
  while(T--)
  {
    solve();
  }
  return 0;
}
